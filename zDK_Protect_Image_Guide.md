# zDK Protect Image Guide

[TOC]

## Summary

There are three types building type for image .

1) traditional flat build  

By default, when you build zDK image , it will generate a single image .

All of the components(drivers, ble stack , application) reside in the same address space ,  

all components can access each others (data , code)

2) Protected Build  

By default, it will generate two images . One is called kernel image, another is user image.

build command:

```sh
$ make pass1
# this will generate user image nuttx_user.elf, nuttx_user.hex
$ make pass2
# this will generate kernel image nuttx, nuttx.hex, nuttx.bin
```



## Memory Protection Unit

The code of kernel image will be executed  in all privileges mode. There privileged threads can access all memory,  

all CPU instruction and all MCU peripheral registers. On the other hand, the code in user image will be executed in  

user mode , and it will be restricted by the MCU and MPU. These restriction can be custimized . Normally, MCU may  

restrict access to certain peripherals and CPU instruction by MPU and access to kernel code & data will be prohibited  

from user mode.



## Advantages of Protected Build

1) Security  

Kernel resources are protected. The key service can run under kernel mode.

2) Modularity  

the interaction bewteen kernel & user is by system call. User application can be developed independently . 



## zDK knsh Example Build

```sh
$ make distclean
$ ./tools/configure.sh -l -a ../apps nrf52840_dk/knsh
$ make pass1
$ make pass2
$ nrfjprog -e
$ nrfjprog --program nuttx.hex
$ nrfjprog --program nuttx_user.hex
```



## zDK knsh Link Script

1) kernel link script is under `configs/nrf52840_dk/script/kernel-space.ld`

2) user image link script is under `configs/nrf52840_dk/script/user-space.ld`

There is no MMU , how the kernel know the user application information ?  

The application information is provided by a litthle trick. There is user header on the begining of user image ,  

then the kernel know the start address of user image and  kernel can get this header information which include  

all data , bss , code , entry point information  like below.

```c
struct userspace_s
{
  /* General memory map */
  main_t    us_entrypoint;
  uintptr_t us_textstart;
  uintptr_t us_textend;
  uintptr_t us_datasource;
  uintptr_t us_datastart;
  uintptr_t us_dataend;
  uintptr_t us_bssstart;
  uintptr_t us_bssend;
    ......
```



## zDK Protected Build Config

This part is reference from [nuttx kernel build](http://www.nuttx.org/doku.php?id=wiki:howtos:kernelbuild&s[]=kernel&s[]=build#nuttx_protected_build) .

- `CONFIG_BUILD_2PASS=y`. This enables the two pass build.

- `CONFIG_BUILD_PROTECTED=y`. This option enables the “two pass” protected build.

- `CONFIG_PASS1_BUILDIR=“configs/nrf52840_dk/kernel”`. This tells the build system the (relative) location of  

  the pass1 build directory.

- `CONFIG_PASS1_OBJECT=””`. In some “two pass” build configurations, the build system need to know the name of  

  the first pass object. This setting is not used for the protected build.

- `CONFIG_NUTTX_USERSPACE=0x08020000.` This is the expected location where the user-mode blob will be located.   

  The user-mode blob contains a header that includes information need by the kernel blob in order to interface  

  with the user-code. That header will be expected to reside at this location.

- `CONFIG_PASS1_TARGET=“all”`. This is the build target to use for invoking the pass1 make.

- `CONFIG_MM_MULTIHEAP=y`. This changes internal memory manager interfaces so that multiple heaps can be supported.

- `CONFIG_MM_KERNEL_HEAP=y`. NuttX supports the option of using a single user-accessible heap or, if this options   

  is defined, two heaps: (1) one that will allocate user accessible memory that is shared by both the kernel- and  

  user-space code, and (2) one that will allocate protected memory that is only accessible from the kernel code.   

  Separate heap memory is required if you want to support security features.

Architecture-Specific Options:

- `CONFIG_SYS_RESERVED=8`. The user application logic interfaces with the kernel blob using system calls.  

  The architecture-specific logic may need to reserved a few system calls for its own internal use.  

  The ARMv7-M architectures all require 8 reserved system calls.

- `CONFIG_SYS_NNEST=2`. System calls may be nested. The system must retain information about each nested  

  system call and this setting is used to set aside resources for nested system calls. In the current  

  architecture, a maximum nesting level of two is all that is needed.

- `CONFIG_ARMV7M_MPU=y`. This settings enables support for the ARMv7-M Memory Protection Unit (MPU).  

  The MPU is used to prohibit user-mode access to kernel resources.

- `CONFIG_ARMV7M_MPU_NREGIONS=8`. The ARMv7-M MPU supports 8 protection regions.