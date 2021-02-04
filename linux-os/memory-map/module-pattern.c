/*************************************************************************
    > File Name: vm-to-pm.c
    > Author: wp 
    > Mail: 
    > Created Time: 2020年05月11日 星期一 21时41分13秒
 ************************************************************************/

#include<linux/module.h>
#include<linux/list.h>
#include<linux/sched.h>

int pid = 0;
module_param(pid, int, 0644);

static int __init start(void)
{
	int pid = 10;
	printk("pid:%d",pid);
	/*
	struct task_struct *pcur;
	struct vm_area_struct *p;

	if (pid) {
		list_for_each_entry(pcur, &current->tasks, tasks) { 
			if (pid == pcur->pid) {
				printk("search pid: %d, and process name is :%s", pid, pcur->comm);
				printk("process user space map:");
				printk("text segment: %lx - %lx", pcur->mm->start_code, pcur->mm->end_code);
				printk("data segment: %lx - %lx", pcur->mm->start_data, pcur->mm->end_data);
				printk("heap segment: %lx - %lx", pcur->mm->start_brk, pcur->mm->brk);
				printk("stack segment: * - %lx", pcur->mm->start_stack);
				p = pcur->mm->mmap;
				if ( p != NULL ) {
					do {
                        printk("virtual memory area: %lx - %lx", p->vm_start, p->vm_end);
						p = p->vm_next;
					} while (p);
				}
			}

		}
	}
	*/
	return 0;
}
module_init(start);

static void __exit end(void)
{
	printk("bye");
}
module_exit(end);

MODULE_LICENSE("GPL");
