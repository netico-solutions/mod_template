
#ifndef CHANNEL_CONTEXT
#define CHANNEL_CONTEXT

#include <linux/mutex.h>

struct channel_context
{
    struct mutex                lock;
};

int channel_init(struct channel_context * ctx);
void channel_term(struct channel_context * ctx);

#endif /* CHANNEL_CONTEXT */
