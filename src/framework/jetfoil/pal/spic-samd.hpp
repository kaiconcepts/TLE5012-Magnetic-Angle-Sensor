/**
 * @file        spic-arduino.hpp
 * @brief       Arduino PAL for the SPI cover
 * @date        June 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */



#ifndef SPIC_SAMD_HPP_
#define SPIC_SAMD_HPP_

#include "../../../config/tle5012-conf.hpp"

#if (TLE5012_FRAMEWORK == TLE5012_FRMWK_JETFOIL)

#include "Arduino.h"
#include "SPI.h"
#include "../../../pal/spic.hpp"

/**
 * @addtogroup arduinoPal
 * @{
 */

/**
 * @brief Arduino SPIC class
 * This function is setting the basics for a SPIC and the default spi.
 */

#define SPEED            1000000U       //!< default speed of SPI transfer

class SPICIno: virtual public SPIC
{
	private:

		uint8_t       csPin   = 0;          //<! \brief hipselect pin for the device
		uint8_t       misoPin = PIN_SPI_MISO;        //<! \brief SPI miso pin
		uint8_t       mosiPin = PIN_SPI_MOSI;        //<! \brief SPI mosi pin
		uint8_t       sckPin  = PIN_SPI_SCK;         //<! \brief SPI system clock pin
		SPIClass    *spi;                          //<! \brief extended SPI class pointer

	public:
					SPICIno(uint8_t csPin=0);
					SPICIno(SPIClass &port, uint8_t csPin=0, uint8_t misoPin=PIN_SPI_MISO, uint8_t mosiPin=PIN_SPI_MOSI, uint8_t sckPin=PIN_SPI_SCK);
					~SPICIno();
		Error_t     init();
		Error_t     deinit();
		Error_t     triggerUpdate();
		Error_t     sendReceive(uint16_t* sent_data, uint16_t size_of_sent_data, uint16_t* received_data, uint16_t size_of_received_data);

};

/** @} */

#endif /** TLE5012_FRAMEWORK **/
#endif /** SPIC_ARDUINO_HPP_ **/
