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
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/uaccess.h>

#include "plat/compiler.h"

#include "xmodule_ioctl.h"
#include "drv/main.h"
#include "drv/kmlog.h"
#include "drv/debug.h"

#define THIS_MODULE_NAME                "xmodule"
#define THIS_MODULE_AUTHOR              "Nenad Radulovic <nenad.b.radulovic@gmail.com"
#define THIS_MODULE_DESCRIPTION         "Generic Lunux Kernel template"
#define THIS_MODULE_VERSION_MAJOR       "1"
#define THIS_MODULE_VERSION_MINOR       "0"

#define THIS_MODULE_VERSION             THIS_MODULE_VERSION_MAJOR "." THIS_MODULE_VERSION_MINOR

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

static struct miscdevice g_xmodule_dev =
{
    .minor              = MISC_DYNAMIC_MINOR,
	.name               = THIS_MODULE_NAME,
	.fops               = &g_xmodule_fops
};

static DEFINE_MUTEX(g_xmodule_global_lock);

static ssize_t xmodule_read(struct file * fd, char __user * user, size_t size, 
        loff_t * offset)
{
    KML_INFO("read\n");
    
    return (0);
}

static ssize_t xmodule_write(struct file * fd, const char __user * user, 
        size_t size, loff_t * offset)
{
    KML_INFO("write\n");
    return (0);
}

static long xmodule_ioctl(struct file * file, unsigned int cmd, 
        unsigned long arg)
{
    long                        retval;

    KML_INFO("ioctl\n");

    switch (cmd) {
        case XMODULE_HARD_RESET : {
            retval = 0;
            break;
        }
        case XMODULE_VERSION : {
            retval = 0;
            copy_to_user((void __user *)arg, THIS_MODULE_VERSION, 
                sizeof(THIS_MODULE_VERSION));
            break;
        }
        default : {
            retval = EINVAL;
            break;
        }
    };
    
    return (retval);
}

static int xmodule_mmap(struct file * file, struct vm_area_struct * vma)
{
    KML_INFO("mmap\n");
		
	return (0);
}

static int xmodule_open(struct inode * inode, struct file * file)
{
    KML_INFO("open: %d:%d\n", current->group_leader->pid, current->pid);

     
    
    return (0);
}

static int     xmodule_flush(struct file * fd, fl_owner_t id)
{
    KML_INFO("flush\n");
    
    return (0);
}

static int     xmodule_release(struct inode * inode, struct file * fd)
{
    KML_INFO("release\n");
    
    return (0);
}

static int __init module_initialize(void)
{
    int                 retval;
    
    KML_NOTICE("Loading module\n");
    KML_DBG("registering device driver\n");
    retval = misc_register(&g_xmodule_dev);
    
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
    KML_INFO("deregistering device driver\n");
    misc_deregister(&g_xmodule_dev);
}

module_init(module_initialize);
module_exit(module_terminate);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(THIS_MODULE_AUTHOR);
MODULE_DESCRIPTION(THIS_MODULE_DESCRIPTION);


