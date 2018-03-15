#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "FrameData.h"

FrameData::FrameData(uint8_t *pData, uint32_t dataLen)
:m_pData(NULL),
m_dataLen(0)
{
    m_pData = (uint8_t*)malloc(dataLen);
    memcpy((void *)m_pData, (void*)pData, dataLen);
    m_dataLen = dataLen;
}

FrameData::~FrameData()
{
    if (m_pData){
        free(m_pData);
        m_pData = NULL;
    }
    m_dataLen = 0;
}

int FrameData::get_data(uint8_t *pDataBuf, uint32_t *dataBufLen)
{
    if (!pDataBuf || !dataBufLen){
        printf("input error\n");
        return 0;
    }
    
    if (m_dataLen > *dataBufLen){
        printf("buf len not enough:need len:%d\n", m_dataLen);;
        return -1;
    }
    
    memcpy(pDataBuf, m_pData, m_dataLen);
    *dataBufLen = m_dataLen;
    
    return 0;
}