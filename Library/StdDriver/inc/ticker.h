#ifndef __TICKER_H__
#define __TICKER_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <NUC029FAE.h>
#include <stdio.h>
#include <stdlib.h>

    void ticker_Start(TIMER_T *timer);
    void ticker_Stop(TIMER_T *timer);
    uint32_t ticker_getTick(void);
    void ticker_Delay(uint32_t delayMs);

#ifdef __cplusplus
}
#endif
#endif
