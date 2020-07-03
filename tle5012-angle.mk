#############################################
# Makefile for CYPRESS WICED WICED 43xxx ####
#############################################
# Include library folder in "libraries/drivers/sensors".
# Add lib to demo or snipped to the makefile
# variable $(NAME)_COMPONENTS += libraries/drivers/sensors

NAME := Lib_tle5012_angle

GLOBAL_DEFINES   := TLE5012B_FRAMEWORK=TLE5012B_FRMWK_WICED

GLOBAL_INCLUDES  := src/								\
					src/config							\
					src/pal								\
					src/framework/wiced-43xxx/pal		\
					src/framework/wiced-43xxx/wrapper
#					#src/util	

$(NAME)_SOURCES  := src/Tle5012b.cpp											\
					src/Tle5012b_reg.cpp										\
					src/framework/wiced-43xxx/pal/tle5012b-pal-gpio-wiced.cpp	\
					src/framework/wiced-43xxx/pal/tle5012b-pal-timer-wiced.cpp	\
					src/framework/wiced-43xxx/pal/tle5012b-pal-spi-wiced.cpp	\
					src/framework/wiced-43xxx/wrapper/tle5012b-wiced.cpp		\
					src/framework/wiced-43xxx/wrapper/tle5012b-platf-wiced.cpp	
#					#src/Tle5012b_4wire.cpp	\
#					#src/util/Tle5012b_SPI.cpp 
					
VALID_PLATFORMS	 := CYW943907AEVAL1F