#export THEOS=/Users/trankhang/theos
ARCHS = arm64 #arm64e
DEBUG = 0
FINALPACKAGE = 1
FOR_RELEASE = 1

# 0 to treat warnings as errors, 1 otherwise.
IGNORE_WARNINGS=1


TARGET = iphone:clang:latest:12.0

## Common frameworks ##
PROJ_COMMON_FRAMEWORKS = UIKit Foundation Security QuartzCore CoreGraphics CoreText

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = 34306jit.plist

tkapikeys_CFLAGS = -fobjc-arc
$(TWEAK_NAME)_LDFLAGS += API/libTKAPIKey.a
tkapikeys_CCFLAGS = -std=c++11 -fno-rtti -fno-exceptions -DNDEBUG

ifeq ($(IGNORE_WARNINGS),1)
  tkapikeys_CFLAGS += -w
  tkapikeys_CCFLAGS += -w
endif

tkapikeys_FILES = Menu.mm

tkapikeys_FRAMEWORKS = $(PROJ_COMMON_FRAMEWORKS)

include $(THEOS_MAKE_PATH)/tweak.mk

