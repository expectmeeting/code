/*************************************************************************
    > File Name: vm-to-pm.c
    > Author: wp 
    > Mail: 
    > Created Time: 2020年05月11日 星期一 21时41分13秒
 ************************************************************************/

#include <linux/module.h>
#include <linux/sched.h>
#include <linux/path.h>
#include <linux/fs_struct.h>
#include <linux/dcache.h>
#include <linux/mount.h>
#include <linux/fs.h>

int pid = 0;                 
module_param(pid, int, 0644);

static int __init start(void)
{
	struct task_struct *pcur;
	struct path pwd;
	struct dentry *dentry;
	if (pid) {                                             
		list_for_each_entry(pcur, &current->tasks, tasks) {
			if (pid == pcur->pid) break;   		
		}
	}

	if (pid == 0) return 0;

	/* file system info*/
	pr_info("process pid:%d, struct fs_struct object addr: %px, Users: %d, umask: %x, in_exec: %d", pid, 
			pcur->fs, pcur->fs->users,
			pcur->fs->umask, pcur->fs->in_exec);

	get_fs_pwd(pcur->fs, &pwd);
	dentry = pwd.dentry;
    pr_info("pwd: %s", dentry->d_iname);
	pr_info("pwd dir dentry addr: %px", dentry);
	pr_info("pwd dir parent dentry addr: %px, dir name: %s", dentry->d_parent, dentry->d_parent->d_iname);
	get_fs_root(pcur->fs, &pwd);
	dentry = pwd.dentry;
    pr_info("root directory: %s", dentry->d_iname);
	pr_info("root dir dentry addr: %px", dentry);
	pr_info("root dir parent dentry addr: %px", dentry->d_parent);
/*    pr_info("---- pwd path ----");
	pr_info("parent mountpoint: %s", pwd.mnt->mnt_root->d_parent->d_iname);
	pr_info("parent mountpoint: %s", pwd.mnt->mnt_root->d_parent->d_sb->s_root->d_iname);
	pr_info("same: %s", pwd.mnt->mnt_root->d_parent == pwd.mnt->mnt_root->d_parent->d_sb->s_root? "yes":"no");
	pr_info("current mountpoint: %s", pwd.mnt->mnt_root->d_iname);
	pr_info("current mountpoint: %s", pwd.mnt->mnt_root->d_sb->s_root->d_iname);
	pr_info("same: %s", pwd.mnt->mnt_root == pwd.mnt->mnt_root->d_sb->s_root? "yes":"no");
*/
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
