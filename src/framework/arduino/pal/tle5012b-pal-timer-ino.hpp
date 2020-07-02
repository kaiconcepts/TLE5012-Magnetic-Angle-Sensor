#ifndef TLE5012B_PAL_WICED_HPP_
#define TLE5012B_PAL_WICED_HPP_

#include "../../../config/tle5012b-conf.hpp"

#if (TLE5012B_FRAMEWORK == TLE5012B_FRMWK_WICED)

#include "tle5012b-pal-gpio.hpp"
#include "wiced_platform.h"


class GPIOWiced : virtual public Tle5012b::GPIO
{
    private:
        #define             UNUSED_PIN    (wiced_gpio_t)(WICED_GPIO_51 + 1) /**< Unused pin */
        wiced_gpio_t        pin;                                            /**< GPIO number */
        wiced_gpio_config_t config;                                         /**< GPIO configuration */
        VLogic_t            logic;                                          /**< Pin logic */

    public:
                                GPIOWiced     (wiced_gpio_t          pin,
                                               wiced_gpio_config_t   config,
                                               VLogic_t              logic);
                                GPIOWiced     ();
                               ~GPIOWiced     ();
        Tle5012b::Error_t       init          ();
        Tle5012b::Error_t       deinit        ();
        Tle5012b::Error_t       enableInt     (Tle5012b *ptr);
        Tle5012b::Error_t       disableInt    ();
        IntEvent_t              intEvent      ();
        VLevel_t                read          ();
        Tle5012b::Error_t       write         (VLevel_t level);
        Tle5012b::Error_t       enable        ();
        Tle5012b::Error_t       disable       ();
};

/** @} */

#endif /** TLE5012B_FRAMEWORK **/
#endif /** TLE5012B_PAL_WICED_HPP_ **/
