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
#include <linux/kernel.>
#include <linux/init.h>

#include "plat/compiler.h"

#include "main/main.h"
#include "main/log.h"
#include "main/debug.h"

#define THIS_MODULE_AUTHOR              "Nenad Radulovic <nenad.b.radulovic@gmail.com"
#define THIS_MODULE_DESCRIPTION         "Generic Lunux Kernel template"

static int __init module_initialize(void)
{
    KMLOG(KML_INFO, "Hello world!\n");
    
    return (ERR_NONE);
}

static void __exit module_terminate(void)
{
    KMLOG(KML_INFO, "Unloading module\n");
}

module_init(module_initialize);
module_exit(module_terminate);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(THIS_MODULE_AUTHOR);
MODULE_DESCRIPTION(THIS_MODULE_DESCRIPTION);

