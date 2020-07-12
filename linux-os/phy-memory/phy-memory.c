/*************************************************************************
    > File Name: vm-to-pm.c
    > Author: wp 
    > Mail: 
    > Created Time: 2020年05月11日 星期一 21时41分13秒
 ************************************************************************/

#include<linux/module.h>
#include<linux/list.h>
#include<linux/sched.h>
#include<linux/mmzone.h>
#include<linux/mutex.h>

int pid = 0;
module_param(pid, int, 0644);

static int __init start(void)
{
    int i, j, k, n;
	unsigned long tmp[11];
	struct zone zone;

	printk("struct pg_data_t addr: %px", node_data);
	printk("total nodes: %d, node id: %d", MAX_NUMNODES, node_data[0]->node_id);
	printk("node start pfn: %lu",node_data[0]->node_start_pfn);
	printk("node spanned pfn: %lu",node_data[0]->node_spanned_pages);
	printk("node present pfn: %lu",node_data[0]->node_present_pages);
	printk("node number of zones: %d",node_data[0]->nr_zones);
    
	for (i = 0; i < node_data[0]->nr_zones; i++) {
	    printk("zone id: %d",i);
		printk("zone name: %s", zone.name);
		printk("zone contiguous: %s", zone.contiguous?"yes":"no");
		zone = node_data[0]->node_zones[i];
		printk("zone start pfn: %lu", zone.zone_start_pfn);
		printk("zone managed pfn: %lu", zone.managed_pages);
		printk("zone spanned pfn: %lu", zone.spanned_pages);
		printk("zone present pfn: %lu", zone.present_pages);

		printk("zone free pages are organized: %d level", MAX_ORDER);
		spin_lock_irq(&zone.lock);
		for (j = 0, n = 0, k = 0; j < MAX_ORDER; j++) {
			tmp[j] = zone.free_area[j].nr_free;
        }
		spin_unlock_irq(&zone.lock);
		for (j = 0, n = 0, k = 0; j < MAX_ORDER; j++) {
			n = (1 << j);
		    printk("%d-th level: %d types, nr_free: %lu, %d free pages", 
					j, MIGRATE_TYPES, tmp[j], tmp[j]*n);
			k += tmp[j]*n;
	    }
		printk("zone total %d free pages", k);
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
