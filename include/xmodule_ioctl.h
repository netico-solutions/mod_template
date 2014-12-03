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
#define XMODULE_HARD_RESET                  _IO(XMODULE_IOC_MAGIC, 200)

/* @brief       Get the module version information
 */
#define XMODULE_VERSION                     _IO(XMODULE_IOC_MAGIC, 201)

/* @brief       Get the bit-mask of supported channels
 */
#define XMODULE_CHANNELS                    _IO(XMODULE_IOC_MAGIC, 100)

/* @brief       Bitwise OR mask of channels to sample
 */
#define XMODULE_ENABLE_CHANNELS             _IO(XMODULE_IOC_MAGIC, 101)

/* @brrief      Bitwise AND mask of channels to sample
 */
#define XMODULE_DISABLE_CHANNELS            _IO(XMODULE_IOC_MAGIC, 102)

#endif /* XMODULE_IOCTL_H */
