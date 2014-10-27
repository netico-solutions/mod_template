/*
 * main.c
 * This file is part of module_template
 *
 * Copyright (C) 2014 - Nenad Radulović
 *
 * module_template is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * module_template is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with module_template. If not, see <http://www.gnu.org/licenses/>.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/mutex.h>
#include <linux/mm.h>

#include "plat/compiler.h"

#include "drv/main.h"
#include "drv/kmlog.h"
#include "drv/debug.h"

#define THIS_MODULE_NAME                "xmodule"
#define THIS_MODULE_AUTHOR              "Nenad Radulovic <nenad.b.radulovic@gmail.com"
#define THIS_MODULE_DESCRIPTION         "Generic Lunux Kernel template"

struct xmodule_proc 
{
    int                 pid;
    uint32_t            id;
};

/*-- Driver file operations --------------------------------------------------*/
static ssize_t xmodule_read(struct file *, char __user *, size_t, loff_t *);
static ssize_t xmodule_write(struct file *, const char __user *, size_t, loff_t *);
static long    xmodule_ioctl(struct file *, unsigned int, unsigned long);
static int     xmodule_mmap(struct file *, struct vm_area_struct *);
static int     xmodule_open(struct inode *, struct file *);
static int     xmodule_flush(struct file *, fl_owner_t id);
static int     xmodule_release(struct inode *, struct file *);

static struct file_operations g_xmodule_fops =
{
    .owner              = THIS_MODULE,
    .read               = xmodule_read,
    .write              = xmodule_write,
    .unlocked_ioctl     = xmodule_ioctl,
    .mmap               = xmodule_mmap,
    .open               = xmodule_open,
    .flush              = xmodule_flush,
    .release            = xmodule_release
};

static struct miscdevice g_xmodule_miscdev =
{
    .minor              = MISC_DYNAMIC_MINOR,
	.name               = THIS_MODULE_NAME,
	.fops               = &g_xmodule_fops
};

static DEFINE_MUTEX(g_xmodule_lock);

static ssize_t xmodule_read(struct file *, char __user *, size_t, loff_t *);
static ssize_t xmodule_write(struct file *, const char __user *, size_t, loff_t *)
{

}

static long    xmodule_ioctl(struct file * file, unsigned int cmd, unsigned long arg)
{
    KML_INFO("ioctl\n");
}

static int xmodule_mmap(struct file * file, struct vm_area_struct * vma)
{
    KML_INFO("mmap\n");
    KML_DBG("mmap details: pid: %d vma: %lx-%lx (%ld K) vma %lx pagep %lx\n",
		proc->pid, vma->vm_start, vma->vm_end,
		(vma->vm_end - vma->vm_start) / SZ_1K, vma->vm_flags,
		(unsigned long)pgprot_val(vma->vm_page_prot);
		
	return (0);
}

static int xmodule_open(struct inode * inode, struct file * file)
{
    struct xmodule_proc *                   proc;
    
    KML_INFO("open\n");
    KML_DBG("open details: %d:%d\n", current->group_leader->pid, current->pid);
    
    proc = kzalloc(sizeof(*proc), GFP_KERNEL);
    
    if (proc == NULL) {
        return (-ENOMEM);
    }
    proc->pid = current->group_leader->pid;
    file->private_data = proc;
    
    return (0);
}

static int     xmodule_flush(struct file *, fl_owner_t id);
static int     xmodule_release(struct inode *, struct file *);

static int __init module_initialize(void)
{
    int                 retval;
    
    KML_NOTICE("Loading module\n");
    KML_DBG("registering device driver\n")
    retval = misc_register(&g_xmodule_miscdev);
    
    if (retval < 0) {
        goto ERR_MISC_REGISTER;
    }
    
    
    return (ERR_NONE);
    
ERR_MISC_REGISTER:
    KML_ERR("cannot register device driver: %d\n", retval);
    
    return (retval);
}

static void __exit module_terminate(void)
{
    KML_NOTICE("Unloading module\n");
}

module_init(module_initialize);
module_exit(module_terminate);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(THIS_MODULE_AUTHOR);
MODULE_DESCRIPTION(THIS_MODULE_DESCRIPTION);


