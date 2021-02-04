/*************************************************************************
    > File Name: vm-to-pm.c
    > Author: wp 
    > Mail: 
    > Created Time: 2020年05月11日 星期一 21时41分13秒
 ************************************************************************/

#include<linux/module.h>
#include<linux/idr.h>

#define _container_of(ptr,type,member) 

static int __init start(void)
{
	u32 test;
	u32 test1;
	u32 test2;
	u32 test3;
	u32 test4;
	u32 test5;

	int id;
	void *p;
	DEFINE_IDR(idr);

	id = idr_alloc(&idr,&test,5,10,GFP_KERNEL);
	printk("alloc idr: %d, %p", id,&test);
	id = idr_alloc(&idr,&test1,5,10,GFP_KERNEL);
	printk("alloc idr: %d, %p", id,&test1);
	id = idr_alloc(&idr,&test2,5,10,GFP_KERNEL);
	printk("alloc idr: %d, %p", id,&test2);
	id = idr_alloc(&idr,&test3,5,10,GFP_KERNEL);
	printk("alloc idr: %d, %p", id,&test3);
	id = idr_alloc(&idr,&test4,5,10,GFP_KERNEL);
	printk("alloc idr: %d, %p", id,&test4);

	printk("find id 7, ptr - %p",idr_find(&idr,7));

	printk("remove id 8, ptr - %p",idr_remove(&idr,8));
	printk("find id 8, ptr - %p",idr_find(&idr,8));


	printk("replace id 9, ptr - %p, old ptr - %p",&test5, idr_replace(&idr, &test5,9));
	printk("find id 9, ptr - %p",idr_find(&idr,9));
	
	printk("iterator");
	idr_for_each_entry(&idr,p,id)
		printk("id: %d, ptr - %p",id,p);

	if (!idr_is_empty(&idr)) {
		idr_destroy(&idr);
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
