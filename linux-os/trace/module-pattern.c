/*************************************************************************
    > File Name: vm-to-pm.c
    > Author: wp 
    > Mail: 
    > Created Time: 2020年05月11日 星期一 21时41分13秒
 ************************************************************************/

#include<linux/module.h>
#include "test.h"

#define CREATE_TRACE_POINTS
DEFINE_TRACE(test_test);

static void test(void *data,int firstarg, int p){
	printk("this is probe function belongs to hook %d:%d",firstarg, p);
}


static int __init start(void)
{
    register_trace_test_test(test,NULL);
	printk("hello world");

	trace_test_test(1, 2);

	return 0;
}
module_init(start);

static void __exit end(void)
{
	unregister_trace_test_test(test,NULL);
	tracepoint_synchronize_unregister();
	printk("bye");
}
module_exit(end);

MODULE_LICENSE("GPL");
