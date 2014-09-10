#platform
KM_PLATFORM=var-som-am33

#SDK root
KM_SDK_ROOT=/opt/ti-sdk-am335x-evm-07.00.00.00

#Target file system
KM_TARGET_FS_ROOT=$(KM_SDK_ROOT)/targetNFS

#Toolchain prefix
KM_TOOLCHAIN_PREFIX=arm-linux-gnueabihf-

#Toolchain path
KM_TOOLCHAIN_PATH=$(KM_SDK_ROOT)/linux-devkit/sysroots/i686-arago-linux/usr/bin

#Toolchain invacation
KM_TOOLCHAIN=$(KM_TOOLCHAIN_PATH)/$(KM_TOOLCHAIN_PREFIX)

#Linux kernel sources
KM_LINUX_SRC=$(KM_SDK_ROOT)/board-support/VAR-SOM-AM33-SDK7-Kernel


