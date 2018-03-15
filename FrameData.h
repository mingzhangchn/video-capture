#ifndef FrameData_H_
#define FrameData_H_

#include <stdint.h>

class FrameData{
public:
    FrameData(uint8_t *pData, uint32_t dataLen);
    ~FrameData();
    int get_data(uint8_t *pDataBuf, uint32_t *dataBufLen);
    
private:    
    uint8_t *m_pData;
    uint32_t m_dataLen;
};

#endif


