#include <linux/module.h>
#include <linux/init.h>

// 显式声明所有属性 ， 没有 模块信息声明 也不影响编译 MODULE_LICENSE("GPL") 等
static int __init __cold hello_init(void)
{
    printk(KERN_INFO "Hello Kernel World!\n");
    return 0;
}

static void __exit __cold hello_exit(void)
{
    printk(KERN_INFO "Goodbye Kernel World!\n");
}

module_init(hello_init);
module_exit(hello_exit);