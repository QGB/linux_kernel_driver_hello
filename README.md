```bash
只能用root用户编译
rm hello.ko  hello.mod.c  hello.mod.o  hello.o  modules.order  Module.symvers

相比较最初init提交，去除编译警告
root@hi3798mv100:~/kernel_driver# make
make -C /lib/modules/4.4.35_ecoo_81080868/build M=/root/kernel_driver modules
make[1]: Entering directory '/usr/src/linux-headers-4.4.35-v7+'
  CC [M]  /root/kernel_driver/hello.o
  Building modules, stage 2.
  MODPOST 1 modules
  CC      /root/kernel_driver/hello.mod.o
  LD [M]  /root/kernel_driver/hello.ko
make[1]: Leaving directory '/usr/src/linux-headers-4.4.35-v7+'
   

root@hi3798mv100:~/linux_kernel_driver_hello# ls
hello.c  hello.ko  hello.mod.c  hello.mod.o  hello.o  Makefile  modules.order  Module.symvers  README.md

root@hi3798mv100:~/linux_kernel_driver_hello# insmod  /root/linux_kernel_driver_hello/hello.ko
root@hi3798mv100:~/linux_kernel_driver_hello# 

root@hi3798mv100:~/linux_kernel_driver_hello# dmesg|tail -n 1
[5677071.854518] Hello Kernel World!

root@hi3798mv100:~/linux_kernel_driver_hello# lsmod 
Module                  Size  Used by
hello                    798  0

root@hi3798mv100:~/linux_kernel_driver_hello# rmmod hello

root@hi3798mv100:~/linux_kernel_driver_hello# dmesg|tail
[5677071.854518] Hello Kernel World!
[5677178.093318] Goodbye Kernel World!

root@hi3798mv100:~/linux_kernel_driver_hello# lsmod 
Module                  Size  Used by


```