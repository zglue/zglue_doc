[TOC]

## Summary

zDK Segger RTT is based on RTT feature of Segger .  It can be as console to replace real UART hardware.

It had been integrated into Segger Embedded Studio.  It depends on Segger_RTT library and

up_segger_rtt_console.c.

## SEGGER RTT Example Build

1. Build Segger RTT Example

```shell
$ cd nuttx
$ make distclean
$ ./tools/configure.sh -l -a ../apps nrf52840_dk/nsh_rtt
# if you are on macOS, you should use "-m" option instead of "-l"

# Finally, this will generate nuttx, nuttx.bin,nuttx.hex.
$ nrfjprog -e; nrfjprog --program nuttx.hex 
# this will program Segger RTT example image into internal flash
```

Comment:

1. you can follow  https://github.com/zglue/zglue_doc/wiki  IDE Debug Setup Guide to setup your

   debug environment

2. make sure the "RTT Enable" option has been enabled from Project Option.

   ![RTT_option](.\imgs\RTT_option.png)

3. You can debug the source with console from Segger Embedded Studio as below:

   ![rtt_console](.\imgs\rtt_console.png)