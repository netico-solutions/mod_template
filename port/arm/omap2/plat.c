/*
 * plat.c
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

#include "drv/port.h"

#define PORT_CHANNELS                   4
#define PORT_CHANNELS_MASK              0xfu

void port_init(void) 
{

}

uint32_t port_channels(void)
{
    return (PORT_CHANNELS);
}

uint32_t port_channels_mask(void)
{
    return (PORT_CHANNELS_MASK);
}

