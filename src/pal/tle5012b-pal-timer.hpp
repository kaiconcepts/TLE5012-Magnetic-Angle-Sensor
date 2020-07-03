
#ifndef TLE5012B_PAL_TIMER_HPP_
#define TLE5012B_PAL_TIMER_HPP_


#include "../corelib/tle5012b.h"

class Tle5012b::Timer
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
        virtual  Tle5012b::Error_t         start   () = 0;

        /**
         * @brief       Elapsed time since the timer was started 
         * @param[out]  elapsed Time in milliseconds 
         * @return      Timer error code
         * @retval      OK if success
         * @retval      INIT_ERROR if hardware interface error    
         */
        virtual  Tle5012b::Error_t         elapsed (uint32_t &elapsed) = 0;
        
        /**
         * @brief   Stops the timer
         * @return  Timer error code
         * @retval  OK if success
         * @retval  INIT_ERROR if hardware interface error
         */
         virtual  Tle5012b::Error_t        stop    () = 0;
        
        /**
         * @brief       Introduces a delay during the specified time    
         * @param[in]   timeout    Delay time in milliseconds   
         * @return      Timer error code
         * @retval      OK if success
         * @retval      INIT_ERROR if hardware interface error
         */
        virtual  Tle5012b::Error_t         delay   (uint32_t timeout) = 0;
};

/** @} */

#endif /** TLE5012B_PAL_TIMER_HPP_ **/
