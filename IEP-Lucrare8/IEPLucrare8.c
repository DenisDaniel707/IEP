#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init helloWorld_start(void)
{
        printk(KERN_INFO "Hello World!\n");
        return 0;
}

static void __exit helloWorld_end(void)
{
        printk(KERN_INFO "Bye!\n");
}

module_init(helloWorld_start);
module_exit(helloWorld_end);
