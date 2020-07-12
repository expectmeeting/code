/*************************************************************************
    > File Name: vm-to-pm.c
    > Author: wp 
    > Mail: 
    > Created Time: 2020年05月11日 星期一 21时41分13秒
 ************************************************************************/

#include<linux/module.h>

/*
 * record kernel print result by dmesg or vim /var/log/messages 
 * 控制台日志级别：优先级高于该值的消息将被打印至控制台
 *
 * 缺省的消息日志级别：将用该优先级来打印没有优先级的消息
 *
 * 最低的控制台日志级别：控制台日志级别可被设置的最小值（最高优先级）
 *
 * 缺省的控制台日志级别：控制台日志级别的缺省值
 */
static int __init start(void)
{
	printk(KERN_EMERG "EMERG 0");
	printk(KERN_ALERT "ALERT 1");
	printk(KERN_CRIT "CRIT 2");
	printk(KERN_ERR "ERR 3");
	printk(KERN_WARNING "WARNING 4");
	printk(KERN_NOTICE "NOTICE 5");
	printk(KERN_INFO "INFO 6");
	printk(KERN_DEBUG "DEBUG 7");

	return 0;
}
module_init(start);

static void __exit end(void)
{
	printk("bye");
}
module_exit(end);

MODULE_LICENSE("GPL");
