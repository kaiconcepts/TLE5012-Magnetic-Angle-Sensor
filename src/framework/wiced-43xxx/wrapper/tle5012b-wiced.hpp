

#ifndef TLE5012B_WICED_H_
#define TLE5012B_WICED_H_

#include "../../../config/tle5012b-conf.hpp"

#if (TLE5012B_FRAMEWORK == TLE5012B_FRMWK_WICED)

#include <stdint.h>
#include "tle5012b.h"
#include "tle5012b-platf-wiced.hpp"
#include "wiced_platform.h"
 
class Tle5012bWiced : public Tle5012b
{
    public:

     Tle5012bWiced(wiced_gpio_t    outputPin,
                   wiced_gpio_t    powerPin   = UNUSED_PIN);

     Tle5012bWiced(PlatformWICED_t hwPlatf);

};

#endif /** TLE5012B_FRAMEWORK **/
#endif /** TLE5012B_WICED_H_ **/
