# zDK Linux Environment Setup

[TOC]

## System requirement

Win-10 or Win-7 or native Ubuntu-Linux

hardware: 16G RAM



## Setup development tools
```sh
$ sudo apt install gcc vim-gnome git
```



## Setup cross-compiler tools

```shell
$ sudo add-apt-repository ppa:team-gcc-arm-embedded/ppa
$ sudo apt-get update
$ sudo apt-get install gcc-arm-embedded
$ arm-none-eabi-gcc --version
```
 	make sure the arm-none-eabi-gcc version  >= 7.2



## Setup debug environment (J-Link , Embedded Studio)

Download linux version J-Link driver from https://www.segger.com/downloads/jlink

```sh
$sudo dpkg -i JLink_Linux_V634a_x86_64.deb
$JLinkExe --version
```

Download linux version Segger Embedded Studio from https://www.segger.com/downloads/embedded-studio

```sh
$tar -xvf Setup_EmbeddedStudio_ARM_v340_linux_x64.tar.gz
$cd arm_segger_embedded_studio_340_linux_x64
$sudo ./install_segger_embedded_studio
$echo "export PATH=$PATH:/usr/share/segger_embedded_studio_for_arm_3.40/bin" >>~/.bashrc
```

Download linux version SystemView from https://www.segger.com/products/development-tools/systemview/

```sh
$sudo dpkg -i systemview_2.52.1_x86_64.deb
$SystemView
```

Download nRF5x-Command-Line-Tools-Linux64  from https://www.nordicsemi.com/eng/Products/nRF52840

```sh
$sudo tar -xvf nRF5x-Command-Line-Tools_9_7_3_Linux-x86_64.tar  -C /opt
$echo "export PATH=$PATH:/opt/mergehex:/opt/nrfjprog" >> ~/.bashrc
```



## Setup python environment

```sh
$sudo apt-get install libssl-dev
$sudo apt install srecord
$sudo apt install python-pip  python3-pip
$pip3 install cryptography intelhex
```

Comment:

​    If you have issue when doing ./sign_img.h as below errors, please uninstall cryptography

​    firstly , then re-install by pip3 again.
​	AttributeError: '_RSAPrivateKey' object has no attribute 'sign'



## Setup kconfig-mconf environment

Download kconfig-frontends-4.11.0.1.tar.bz2 from http://ymorin.is-a-geek.org/projects/kconfig-frontends

```sh
$ tar -xvf kconfig-frontends-4.11.0.1.tar.bz2
$ cd kconfig-frontends-4.11.0.1
$ sudo apt install flex bison gperf  libncurses-dev ncurses-dev libncurses5-dev libncursesw5-dev
$ ./configure
$ make
$ make install
$ sudo ldconfig
```


## zDK pre-install  virtual machine Image

Please install vmware-player firstly , you can download VMware-player-14.1.1-7528167.exe

And download  the pre-install virtual machine from Zglue ftp server.

```sh
$ unzip zglue_sdk_virtual_machine_x64_20180813.zip
```

