```bash
只能用root用户编译
rm hello.ko  hello.mod.c  hello.mod.o  hello.o  modules.order  Module.symvers

root@hi3798mv100:~/linux_kernel_driver_hello# make                                                                                                                                              [4/32]
make -C /lib/modules/4.4.35_ecoo_81080868/build M=/root/linux_kernel_driver_hello modules                                                                                                             
make[1]: Entering directory '/usr/src/linux-headers-4.4.35-v7+'                                                                                                                           
  CC [M]  /root/linux_kernel_driver_hello/hello.o                                                                                                                                                     
In file included from include/linux/kernel.h:11,                                                                                                                                          
                 from include/linux/list.h:8,                 from include/linux/module.h:9,
                 from /root/linux_kernel_driver_hello/hello.c:5:
include/linux/log2.h:22:1: warning: ignoring attribute ‘noreturn’ because it conflicts with attribute ‘const’ [-Wattributes]   22 | int ____ilog2_NaN(void);
      | ^~~
In file included from /root/linux_kernel_driver_hello/hello.c:5:include/linux/module.h:130:6: warning: ‘init_module’ specifies less restrictive attribute than its target ‘hello_init’: ‘cold’ [-Wmissing-attributes]
  130 |  int init_module(void) __attribute__((alias(#initfn)));
      |      ^~~~~~~~~~~
/root/linux_kernel_driver_hello/hello.c:27:1: note: in expansion of macro ‘module_init’
   27 | module_init(hello_init);
      | ^~~~~~~~~~~
/root/linux_kernel_driver_hello/hello.c:14:19: note: ‘init_module’ target declared here
   14 | static int __init hello_init(void)
      |                   ^~~~~~~~~~
In file included from /root/linux_kernel_driver_hello/hello.c:5:
include/linux/module.h:136:7: warning: ‘cleanup_module’ specifies less restrictive attribute than its target ‘hello_exit’: ‘cold’ [-Wmissing-attributes]
  136 |  void cleanup_module(void) __attribute__((alias(#exitfn)));
      |       ^~~~~~~~~~~~~~
/root/linux_kernel_driver_hello/hello.c:28:1: note: in expansion of macro ‘module_exit’
   28 | module_exit(hello_exit);
      | ^~~~~~~~~~~
/root/linux_kernel_driver_hello/hello.c:21:20: note: ‘cleanup_module’ target declared here
   21 | static void __exit hello_exit(void)
      |                    ^~~~~~~~~~
  Building modules, stage 2.
  MODPOST 1 modules
  CC      /root/linux_kernel_driver_hello/hello.mod.o
In file included from include/linux/kernel.h:11,
                 from include/linux/list.h:8,
                 from include/linux/module.h:9,
                 from /root/linux_kernel_driver_hello/hello.mod.c:1:
include/linux/log2.h:22:1: warning: ignoring attribute ‘noreturn’ because it conflicts with attribute ‘const’ [-Wattributes]
   22 | int ____ilog2_NaN(void);
      | ^~~
In file included from /root/linux_kernel_driver_hello/hello.mod.c:2:
include/linux/vermagic.h:38:1: warning: multi-line comment [-Wcomment]
   38 | // #define VERMAGIC_STRING       \
      | ^
  LD [M]  /root/linux_kernel_driver_hello/hello.ko
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