# Set the name of your application:
APPLICATION = foobar
# If no BOARD is found in the environment, use this default:
BOARD ?= native
# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= $(CURDIR)/../RIOT
include $(RIOTBASE)/Makefile.include
