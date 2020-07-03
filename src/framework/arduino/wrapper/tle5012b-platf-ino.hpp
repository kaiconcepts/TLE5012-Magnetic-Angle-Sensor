
#ifndef TLE5012B_PLATF_INO_HPP_
#define TLE5012B_PLATF_INO_HPP_

#include "../../../config/hall-conf.hpp"

#if (TLE5012B_FRAMEWORK == TLE5012B_FRMWK_ARDUINO)

//#include "tle5012b-pal-wiced.hpp"

/**
 * @brief WICED Hardware Platform
 */
typedef struct
{
    //wiced_gpio_t output;     /**< SPI handle */
    wiced_gpio_t enable;      /**< Power pin */
}PlatformWICED_t;

extern PlatformWICED_t TLE4964_3M_S2Go_MyIoT_CYW943907AEVAL1F;   /**< TLE4964 3M Shield 2Go + MyIOT Adapter + CYW943907AEVAL1F Eval Kit*/

#endif /** TLE5012B_FRAMEWORK **/
#endif /** TLE5012B_PLATF_INO_HPP_ **/
