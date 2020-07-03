
#ifndef TLE5012B_PLATF_WICED_HPP_
#define TLE5012B_PLATF_WICED_HPP_

#include "../../../config/tle5012b-conf.hpp"

#if (TLE5012B_FRAMEWORK == TLE5012B_FRMWK_WICED)

#include "tle5012b-pal-gpio-wiced.hpp"

/**
 * @brief WICED Hardware Platform
 */
typedef struct
{
    //wiced_gpio_t output;    /**< SPI handle */
    wiced_gpio_t enable;      /**< Power pin */
}PlatformWICED_t;

extern PlatformWICED_t TLE5012B_E1000_MS2Go_CYW943907AEVAL1F;   /**< TLE4964 3M Shield 2Go + MyIOT Adapter + CYW943907AEVAL1F Eval Kit*/

#endif /** TLE5012B_FRAMEWORK **/
#endif /** TLE5012B_PLATF_WICED_HPP_ **/
