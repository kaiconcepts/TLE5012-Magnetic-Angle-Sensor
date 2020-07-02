#include "tle5012b-pal-gpio-wiced.hpp"

#if (TLE5012B_FRAMEWORK == TLE5012B_FRMWK_WICED))

//#include "tle5012b-int.hpp"

/**
 * @brief GPIO WICED default constructor
 */
GPIOWiced::GPIOWiced(wiced_gpio_t          pin,
                     wiced_gpio_config_t   config,
                     VLogic_t              logic)
: pin(pin), config(config), logic(logic)
{

}

/**
 * @brief GPIO WICED default constructor
 */
GPIOWiced::GPIOWiced()
:pin(WICED_GPIO_1), config(INPUT_HIGH_IMPEDANCE), logic(POSITIVE)
{

}

/**
 * @brief GPIO WICED destructor
 */
GPIOWiced::~GPIOWiced()
{
    disable();
    deinit();
}

/**
 * @brief   Initializes the WICED GPIO
 * @return  GPIO error code
 * @retval  OK if success
 * @retval  INTF_ERROR if initialization error
 */
inline Tle5012b::Error_t GPIOWiced::init()
{   
    Tle5012b::Error_t err = Tle5012b::NO_ERROR;
    if(WICED_SUCCESS != wiced_gpio_init(pin, config))
        err = Tle5012b::PAL_ERROR;

    return err;
}

/**
 * @brief   Initializes the WICED GPIO
 * @return  GPIO error code
 * @retval  OK if success
 * @retval  INTF_ERROR if deinitialization error
 */
inline Tle5012b::Error_t GPIOWiced::deinit()
{
    Tle5012b::Error_t err = Tle5012b::NO_ERROR;
    if(WICED_SUCCESS != wiced_gpio_deinit(pin))
        err = Tle5012b::PAL_ERROR;

    return err;
}

/**
 * @brief   Enables the WICED GPIO interrupt
 * @return  GPIO error code
 * @retval  OK if success
 * @retval  INTF_ERROR if error
 */
inline Tle5012b::Error_t GPIOWiced::enableInt(Tle5012b *ptr)
{
    Tle5012b::Error_t err = Tle5012b::NO_ERROR;

    if(WICED_SUCCESS != wiced_gpio_input_irq_enable(pin,IRQ_TRIGGER_BOTH_EDGES, (wiced_gpio_irq_handler_t)(HallSwitch::Interrupt::isrRegister(ptr)),NULL))
        err = Tle5012b::PAL_ERROR;

    return err;
}

/**
 * @brief   Disables the WICED GPIO interrupt
 * @return  GPIO error code
 * @retval  OK if success
 * @retval  INTF_ERROR if error
 */
inline Tle5012b::Error_t GPIOWiced::disableInt()
{
    Tle5012b::Error_t err = Tle5012b::NO_ERROR;

    if(WICED_SUCCESS != wiced_gpio_input_irq_disable(pin))
        err = Tle5012b::PAL_ERROR;

    return err;
}

/**
 * @brief   Gets the latest WICED interrupt event
 * @return  GPIO interrupt event
 * @retval  INT_FALLING_EDGE if falling edge event
 * @retval  INT_RISING_EDGE if rising edge event
 */
inline GPIOWiced::IntEvent_t GPIOWiced::intEvent()
{
    IntEvent_t event = INT_FALLING_EDGE;
    wiced_bool_t val = wiced_gpio_input_get(this->pin);

    if(WICED_FALSE == val )
    {
        event = INT_FALLING_EDGE;
    }
    else if(WICED_TRUE == val)
    {
        event = INT_RISING_EDGE;
    }

    return event;
}

/**
 * @brief       Reads the WICED GPIO voltage level
 * @return      GPIO voltage level
 * @retval      GPIO_LOW if voltage low
 * @retval      GPIO_HIGH if voltage high
 */
inline GPIOWiced::VLevel_t GPIOWiced::read()
{
    return (VLevel_t) wiced_gpio_input_get(pin);
}

/**
 * @brief       Writes the WICED GPIO output voltage level
 * @param[in]   level  Voltage level
 * @return      GPIO error code
 * @retval      OK if success
 * @retval      INTF_ERROR if error
 */
inline Tle5012b::Error_t GPIOWiced::write(VLevel_t level)
{
    Tle5012b::Error_t err = Tle5012b::NO_ERROR;

    if(GPIO_LOW == level)
    {
        if(WICED_SUCCESS != wiced_gpio_output_low(pin))
            err = Tle5012b::PAL_ERROR;
    }
    else if(GPIO_HIGH == level)
    {
        if(WICED_SUCCESS != wiced_gpio_output_high(pin))
            err = Tle5012b::PAL_ERROR;
    }

    return err;
}

/**
 * @brief       Enables the WICED output according to the GPIO logic
 *              - Low if negative
 *              - High if positive
 * @return      GPIO interrupt event
 * @retval      OK if success
 * @retval      INTF_ERROR if error
 */
inline Tle5012b::Error_t GPIOWiced::enable()
{
    Tle5012b::Error_t err = Tle5012b::NO_ERROR;

    if(this->logic == POSITIVE)
    {
        if(WICED_SUCCESS != wiced_gpio_output_high(pin))
            err = Tle5012b::PAL_ERROR;
    }
    else if(this->logic == NEGATIVE)
    {
        if(WICED_SUCCESS != wiced_gpio_output_low(pin))
            err = Tle5012b::PAL_ERROR;
    }
    return err;
}

/**
 * @brief       Disables the WICED output according to the GPIO logic
 *              - Low if positive
 *              - High if negative
 * @return      GPIO error code
 * @retval      OK if success
 * @retval      INTF_ERROR if error
 */
inline Tle5012b::Error_t GPIOWiced::disable()
{
    Tle5012b::Error_t err = Tle5012b::NO_ERROR;

    if(this->logic == POSITIVE)
    {
        if(WICED_SUCCESS != wiced_gpio_output_low(pin))
            err = Tle5012b::PAL_ERROR;
    }
    else if(this->logic == NEGATIVE)
    {
        if(WICED_SUCCESS != wiced_gpio_output_high(pin))
            err = Tle5012b::PAL_ERROR;
    }
    return err;
}

#endif /** TLE5012B_FRAMEWORK **/
