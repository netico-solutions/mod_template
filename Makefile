-include Rules.make

# --  Kernel module specifics  ----------------------------------------------- #

# HW Agnostic objects
KM_BASE_OBJS        := src/main.o src/debug.o
KM_BASE_INC         := inc

# Port objects
KM_PORT_ARCH        := arm
KM_PORT_PLAT        := $(KM_PORT_ARCH)/omap2

KM_PORT_OBJS        := port/$(KM_PORT_PLAT)/plat.o
KM_PORT_ARCH_INC    := port/$(KM_PORT_ARCH)
KM_PORT_PLAT_INC    := port/$(KM_PORT_ARCH_INC)/$(KM_PORT_PLAT)

am335x-mod-y        := $(KM_BASE_OBJS) $(KM_PORT_OBJS)
obj-m               += am335x-mod.o

KM_INC              := -I$(PWD)/$(KM_BASE_INC) -I$(PWD)/$(KM_PORT_ARCH_INC)     \
                       -I$(PWD)/$(KM_PORT_PLAT_INC)
EXTRA_CFLAGS        += $(KM_INC)

all:
	@echo ========================================
	@echo     Building the Linux Kernel Module
	@echo ========================================
	$(MAKE) -C $(KM_LINUX_SRC) ARCH=$(KM_PORT_ARCH)                             \
	    CROSS_COMPILE=$(KM_TOOLCHAIN) M=$(PWD) modules
	    
clean:
    make -C $(LINUX_SRC) M=$(PWD) clean
