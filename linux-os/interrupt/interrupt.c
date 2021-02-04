/*************************************************************************
    > File Name: intrrupt.c
    > Author: wp 
    > Mail: 
    > Created Time: 2020年05月11日 星期一 21时41分13秒
 ************************************************************************/

#include<linux/module.h>
#include<linux/interrupt.h>

struct arg_list{
	char name[10];
	int irq; 
};

static irqreturn_t my_irq(int irq, void *arg)
{
    printk(KERN_INFO"my irq: %d",irq);
	return IRQ_HANDLED;
}

static int __init start(void)
{
	int i;
	struct arg_list arg = { 
		.name = "test",
	    .irq =0, };
	
	i = request_irq(0, my_irq, IRQF_SHARED, "my_irq", &arg);

	printk("hello world");
	return 0;
}
module_init(start);

static void __exit end(void)
{
	struct arg_list arg = {
		    .name = "test",    
			.irq =0, 
	};        
	free_irq(0, &arg);
	printk("bye");
}
module_exit(end);

MODULE_LICENSE("GPL");
