#ifndef TLE5012B_INO_H_
#define TLE5012B_INO_H_

#include "../../../config/tle5012b-conf.hpp"

#if (TLE5012B_FRAMEWORK == TLE5012B_FRMWK_ARDUINO)

#include <stdint.h>
#include <SPI.h>
#include "Tle5012b.h"
#include "Tle5012b-platf-wiced.hpp"

class Tle5012bIno : public Tle5012b
{
    public:

     Tle5012bIno(SPIClass * bus = &SPI,
                 uint8_t    powerPin   = UNUSED_PIN);
     Tle5012bIno(PlatformIno_t hwPlatf);

};

#endif /** TLE5012B_FRAMEWORK **/
#endif /** TLE5012B_INO_H_ **/
