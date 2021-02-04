/*************************************************************************
    > File Name: vm-to-pm.c
    > Author: wp 
    > Mail: 
    > Created Time: 2020年05月11日 星期一 21时41分13秒
 ************************************************************************/

#include<linux/module.h>
#include<linux/kthread.h>
#include<linux/delay.h>


static struct task_struct *k;
int task(void *data){
	printk("kernel thread test\n");
	
	while (!kthread_should_stop()) {
		msleep(10);
	}
	return 0;
}

static int __init start(void)
{
	k = kthread_create(task,NULL,"mythread");
	if (!IS_ERR(k)) {
		wake_up_process(k);
	}
	printk("hello world");
	return 0;
}
module_init(start);

static void __exit end(void)
{
	if(pid_alive(k)) { 
		printk("thread not dead\n");
		kthread_stop(k);
	} else {
		printk("thread dead\n");
	}
	printk("bye");
}
module_exit(end);

MODULE_LICENSE("GPL");
