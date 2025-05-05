/* 
 * 最简单的Linux内核模块示例
 * 功能：加载时打印消息，不实现任何设备操作
 */
#include <linux/module.h>  // 所有模块必需的头文件
#include <linux/kernel.h>  // 包含printk等内核API

/* 模块信息声明（必须） */
MODULE_LICENSE("GPL");              // 开源许可证
MODULE_AUTHOR("Your Name");         // 作者
MODULE_DESCRIPTION("Minimal kernel module demo"); // 描述

/* 模块初始化函数 */
static int __init hello_init(void)
{
    printk(KERN_INFO "Hello Kernel World!\n"); // 内核日志输出
    return 0; // 返回0表示成功
}

/* 模块清理函数 */
static void __exit hello_exit(void)
{
    printk(KERN_INFO "Goodbye Kernel World!\n");
}

/* 注册初始化/退出函数 */
module_init(hello_init);
module_exit(hello_exit);
