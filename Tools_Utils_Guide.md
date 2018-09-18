# Tools Utils Guide

[TOC]

## Code Analysis Usage

It  depends on the `CONFIG_CODE_ANALYSIS=y` config  option, please make sure the option  

has been enabled.

```sh
$ ./code_analysis.sh nuttx.map
```

By default,  it will generate code, data, bss section information of each modules.

The modules are `sched, mm, c_cxx, fs, drivers, soc, apps, others`

> `sched` module is  schedule module information. Code located in **sched**
>
> `mm` module is memory module information . Code located in **mm**
>
> `c_cxx` is c & c++ library module information. Code located in **libs/libc  libs/libcxx**
>
> `fs` is file system module information. Code located in **fs**
>
> `drivers` is  each hal driver module information . Code located in **drivers**
>
> `soc` is the chip  low level driver module information. Code located  in **arch/arm/src/chip**
>
> `apps` is the application module information. Code  located in **apps**
>
> `other` is the rest module information .

Another tool is GNU size , it can provide  the summary about  text, data , bss section information.

Example as below:

```sh
levin@ubuntu:~/project/work/nuttx$ arm-none-eabi-size nuttx
   text	   data	    bss	    dec	    hex	filename
 167880	    492	   6884	 175256	  2ac98	nuttx
```

When you do code size optimization , you can use  code analysis to analyze each module and do special  

optimization.



## Code Stack Analysis Usage

It depends on the CFLAGS `-fstack-usage`, please make sure it has been added from your project.

```sh
usage: stack_analysis.py [options] 

Analyze the static stack size of function

optional arguments:
  -h, --help            show this help message and exit
  --directory DIRECTORY [DIRECTORY ...], -d DIRECTORY [DIRECTORY ...]
                        The directory which will be searched for stack
                        analysis
  --function FUNCTION, -f FUNCTION
                        The name of function which will be analyzed
  --version, -v         show program's version number and exit

```

Examples:

```sh
levin@ubuntu:~/project/work/nuttx$ ./stack_analysis.py -d .   -f nrf52_serial_thread
System Max recursionlimit(): 1000
Set system Max recursionlimit(): 2000
Enter function stack & call graph analysis
Total su files : 1502
Total API  : 1845
call_graph Directory FileExist
Function                               Stack       Frame
========================================================
>>nrf52_serial_thread                    208          24
  uart_xmitchars                         184          24
  uart_datasent                          160          16
  nxsem_post                             144          48
  up_unblock_task                         96          24
  sched_addreadytorun                     72          24
  sched_addprioritized                    48          32
  up_assert                               16          16

```

The max stack size of api nrf52_serial_thread is 208 bytes.



## Image Sign Tools Usage

It depends on pthon3 and python3 modules(`cryptography`, `intelhex`) . Please make sure you have  

followed the `zDK-Linux-Environment-Setup-Guide` to install right envrionment.

```sh
Usage:
 1. export IMG_VERSION=x.x.x+xxx
 	 version is major.minus.rev+build
 	 option: 
 	   export IMG_START=xxxxx
 	 	  this is the location of image in flash
 	   export IMG_LEN=xxxx
 	 	  this is the total length of signed image
 2. ./sign_img.sh [ private_key.pem ]
 
Finally, it will generate  *.sign.hex , *.sign.bin
```

`Comment`

> ​	

> Defaultly, the tool will read  *CONFIG_FLASH_ORIGIN*  as `IMG_START` , *CONFIG_FLSH_LENGTH* as `IMG_LEN` . 
>
> Even the total image length is less than  IMG_LEN , this tool will pad the signed image to `IMG_LEN`

Examples:

```bash
$ IMG_VERSION="1.0.0" ./sign_img.sh

# if the image is located in flash from 0x60000 , you can use below command
$ IMG_START=0x60000 ./sign_img.sh
```

