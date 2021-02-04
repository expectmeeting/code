/*************************************************************************
    > File Name: vm-to-pm.c
    > Author: wp 
    > Mail: 
    > Created Time: 2020年05月11日 星期一 21时41分13秒
 ************************************************************************/

#include<linux/module.h>
#include<linux/sched.h>
#include <linux/bug.h>
#include<linux/list.h>

static int __init start(void)
{
    BUG();
	printk("kernel stack size: %ld",THREAD_SIZE);
	struct task_struct *pcur;

		list_for_each_entry(pcur, &current->tasks, tasks) { 
			if (0 == pcur->pid) {
				printk("pid: %d, stack: %px, thread_info: %px, task_struct: %px, magic: 0x%08X", 
						pcur->pid, pcur->stack,task_thread_info(pcur), pcur, *(u32 *)pcur->stack);
			} else if (1 == pcur->pid) {
				printk("pid: %d, stack: %px, thread_info: %px, task_struct: %px, magic: 0x%08X", 
						pcur->pid, pcur->stack,task_thread_info(pcur), pcur, *(u32 *)pcur->stack);
			} else if (2 == pcur->pid) {
				printk("pid: %d, stack: %px, thread_info: %px, task_struct: %px, magic: 0x%08X", 
						pcur->pid, pcur->stack,task_thread_info(pcur), pcur, *(u32 *)pcur->stack);
			}
		}
	return 0;
}
module_init(start);

static void __exit end(void)
{
	printk("bye");
}
module_exit(end);

MODULE_LICENSE("GPL");
