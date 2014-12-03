
#include "drv/channel_context.h"

int channel_init(struct channel_context * ctx)
{
    mutex_init(&ctx->lock);
    
    return (0);
}

void channel_term(struct channel_context * ctx)
{
    
}
