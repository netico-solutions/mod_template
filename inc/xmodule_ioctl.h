/*
 * <filename>
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

#ifndef XMODULE_IOCTL_H
#define XMODULE_IOCTL_H

#define XMODULE_IOC_MAGIC                   'x'

/* @brief       This is used to reset the module's usage count to 0 so that the 
 *              module can be unloaded should something go wrong with the 
 *              counter.
 */
#define XMODULE_HART_RESET                  _IO(XMODULE_IOC_MAGIC, 200)

#endif /* XMODULE_IOCTL_H */
