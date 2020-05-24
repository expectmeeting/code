/*************************************************************************
    > File Name: vm-to-pm.c
    > Author: wp 
    > Mail: 
    > Created Time: 2020年05月11日 星期一 21时41分13秒
 ************************************************************************/

#include<linux/module.h>

static int __init start(void)
{
	printk("hello world");
	return 0;
}
module_init(start);

static void __exit end(void)
{
	printk("bye");
}
module_exit(end);

MODULE_LICENSE("GPL");
