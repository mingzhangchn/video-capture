#ifndef FrameQueue_H_
#define FrameQueue_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif    

int frame_put(uint8_t *pData, uint32_t dataLen);
int frame_get(uint8_t *pDataBuf, uint32_t *dataBufLen);
    
#ifdef __cplusplus    
}
#endif

#endif