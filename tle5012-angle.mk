#############################################
# Makefile for CYPRESS WICED WICED 43xxx ####
#############################################
# Include library folder in "libraries/drivers/sensors".
# Add lib to demo or snipped to the makefile
# variable $(NAME)_COMPONENTS += libraries/drivers/sensors

NAME := Lib_tle5012_angle

#GLOBAL_DEFINES   := HALL_SWITCH_FRAMEWORK=HALL_SWITCH_FRMWK_WICED

GLOBAL_INCLUDES  := src/		\
					#src/util	

$(NAME)_SOURCES  := src/Tle5012b.cpp		\
					#src/Tle5012b_4wire.cpp	\
					#src/Tle5012b_reg.cpp	\
					#src/util/Tle5012b_SPI.cpp 
					
VALID_PLATFORMS	 := CYW943907AEVAL1F