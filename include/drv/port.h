
#ifndef PORT_H_
#define PORT_H_

#include "linux/types.h"

void port_int(void);
uint32_t port_channels(void);
uint32_t port_channels_mask(void);

#endif /* PORT_H_ */
