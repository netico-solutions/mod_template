/*
 * log.h
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

#ifndef KMLOG_H
#define KMLOG_H

#include <linux/printk.h>
#include "drv/config.h"

#define KML_OFF                             0

#define KML_ERR_LEVEL                       1
#define KML_WARN_LEVEL                      2
#define KML_NOTICE_LEVEL                    3
#define KML_INFO_LEVEL                      4
#define KML_DBG_LEVEL                       5

#define KML_GLOBAL_LEVEL                    KML_DBG_LEVEL  

#if (KML_GLOBAL_LEVEL >= KML_INFO_LEVEL)
#define KML_DBG(text, ...)                                                      \
    printk(KERN_DEBUG CONFIG_XMODULE_NAME ": " text, # __VA_ARGS__)
#else
#define KML_DBG()                           (void)0
#endif

#if (KML_GLOBAL_LEVEL >= KML_DBG_LEVEL)
#define KML_INFO(text, ...)                                                     \
    printk(KERN_INFO CONFIG_XMODULE_NAME ": " text, # __VA_ARGS__)
#else
#define KML_INFO()                          (void)0
#endif

#if (KML_GLOBAL_LEVEL >= KML_NOTICE_LEVEL)
#define KML_NOTICE(text, ...)                                                   \
    printk(KERN_NOTICE CONFIG_XMODULE_NAME ": " text, # __VA_ARGS__)
#else
#define KML_NOTICE()                        (void)0
#endif

#if (KML_GLOBAL_LEVEL >= KML_WARN_LEVEL)
#define KML_WARN(text, ...)                                                     \
    printk(KERN_WARNING CONFIG_XMODULE_NAME ": " text, # __VA_ARGS__)
#else
#define KML_WARN()                          (void)0
#endif

#if (KML_GLOBAL_LEVEL >= KML_ERR_LEVEL)
#define KML_ERR(text, ...)                                                      \
    printk(KERN_ERR CONFIG_XMODULE_NAME ": " text, # __VA_ARGS__)
#else
#define KML_ERR()                           (void)0
#endif

#endif /* KMLOG_H */

