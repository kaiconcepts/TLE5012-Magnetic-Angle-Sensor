#ifndef TLE5012B_PAL_SPI_HPP_
#define TLE5012B_PAL_SPI_HPP_

#include "../corelib/tle5012b.h"

class Tle5012b::SPI
{
    public:

        /**
         * @brief   Initialiazes the timer
         * @return  Timer error code
         * @retval  OK if success
         * @retval  INIT_ERROR if hardware interface error
         */
        virtual  Tle5012b::Error_t         init    () = 0;

        /**
         * @brief   Deinitialiazes the timer
         * @return  Timer error code
         * @retval  OK if success
         * @retval  INIT_ERROR if hardware interface error
         */
        virtual  Tle5012b::Error_t         deinit  () = 0;

        /**
         * @brief   Starts the timer
         * @return  Timer error code
         * @retval  OK if success
         * @retval  INIT_ERROR if hardware interface error
         */
        virtual  Tle5012b::Error_t         write   () = 0;

        /**
         * @brief       Elapsed time since the timer was started
         * @param[out]  elapsed Time in milliseconds
         * @return      Timer error code
         * @retval      OK if success
         * @retval      INIT_ERROR if hardware interface error
         */
        virtual  Tle5012b::Error_t         transfer(uint16_t* sent_data, uint16_t size_of_sent_data, uint16_t* received_data, uint16_t size_of_received_data) = 0;

        /**
         * @brief   Stops the timer
         * @return  Timer error code
         * @retval  OK if success
         * @retval  INIT_ERROR if hardware interface error
         */
         virtual  Tle5012b::Error_t        stop    () = 0;

};

#endif /** TLE5012B_PAL_SPI_HPP_ **/

