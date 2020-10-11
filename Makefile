# Set the name of your application:
APPLICATION = STynth
# If no BOARD is found in the environment, use this default:
BOARD ?= native

USEMODULE += xtimer

FEATURES_REQUIRED += periph_gpio
FEATURES_REQUIRED += periph_gpio_irq
CFLAGS += -DAUTO_INIT_LED0

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= $(CURDIR)/../RIOT
include $(RIOTBASE)/Makefile.include
