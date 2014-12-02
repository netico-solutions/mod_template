# Configuration file for kernel compilation process
# DO NOT USE RELATIVE PATHS

#platform
KM_PLATFORM=var-som-am33

#kernel configuration
KM_CONFIG=tisdk_$(KM_PLATFORM)_defconfig

#Architecture
KM_ARCH=arm

#Platform
KM_PLAT:=omap2

#SDK root
KM_SDK_ROOT=/home/nenad/ti-sdk-am335x-evm-07.00.00.00

#Target file system
KM_TARGET_FS=$(KM_SDK_ROOT)/targetNFS

#Toolchain prefix
KM_TOOLCHAIN_PREFIX=arm-linux-gnueabihf-

#Toolchain path
KM_TOOLCHAIN_PATH=$(KM_SDK_ROOT)/linux-devkit/sysroots/i686-arago-linux/usr/bin

#Toolchain invacation
KM_TOOLCHAIN=$(KM_TOOLCHAIN_PATH)/$(KM_TOOLCHAIN_PREFIX)

#Linux kernel sources
KM_LINUX_SRC=$(KM_SDK_ROOT)/board-support/VAR-SOM-AM33-SDK7-Kernel

# Number of CPU threads
KM_JOBS=4

# --  Kernel module specifics  ----------------------------------------------- #

# HW Agnostic objects
KM_BASE_OBJS        := source/main.o source/debug.o
KM_BASE_INC         := include

# Port objects
KM_PORT_OBJS        := port/$(KM_ARCH)/$(KM_PLAT)/plat.o
KM_PORT_ARCH_INC    := port/${KM_ARCH}
KM_PORT_PLAT_INC    := port/$(KM_ARCH)/$(KM_PLAT)

am335x-mod-y        := $(KM_BASE_OBJS) $(KM_PORT_OBJS)
obj-m               += am335x-mod.o

KM_INC              := -I$(PWD)/$(KM_BASE_INC) -I$(PWD)/$(KM_PORT_ARCH_INC)     \
                       -I$(PWD)/$(KM_PORT_PLAT_INC)
EXTRA_CFLAGS        += $(KM_INC)

all:
	@echo ========================================
	@echo     Building the Linux Kernel Module
	@echo ========================================
	$(MAKE) -C $(KM_LINUX_SRC) ARCH=$(KM_ARCH)                             \
	    CROSS_COMPILE=$(KM_TOOLCHAIN) M=$(PWD) modules
	    
clean:
	make -C $(LINUX_SRC) M=$(PWD) clean
