#include <stdio.h>

#include <queue>
#include <semaphore.h>
#include <stdint.h>
#include "FrameData.h"

#include "FrameQueue.h"

class FrameQueue{
public:
    FrameQueue();
    ~FrameQueue();
    int add_frame(uint8_t *pData, uint32_t dataLen);
    int get_frame(uint8_t *pDataBuf, uint32_t *dataBufLen);
    
private:
    sem_t m_sem;
    std::queue<FrameData*> m_frameQueue;
};

FrameQueue::FrameQueue()
{
    sem_init(&m_sem, 0, 0);
}

FrameQueue::~FrameQueue()
{
    sem_destroy(&m_sem);
}

int FrameQueue::add_frame(uint8_t *pData, uint32_t dataLen)
{
    FrameData *pFrame = new FrameData(pData, dataLen);
    m_frameQueue.push(pFrame);
    sem_post(&m_sem);
}

int FrameQueue::get_frame(uint8_t *pDataBuf, uint32_t *dataBufLen)
{
    sem_wait(&m_sem);//blocked
    if(!m_frameQueue.empty()){
        FrameData *pFrame = m_frameQueue.front();
        m_frameQueue.pop();
        pFrame->get_data(pDataBuf, dataBufLen);
        delete(pFrame);
        //printf("got frame\n");
        return 0;
    } 
    
    return -1;
}



static FrameQueue f_queue;

int frame_put(uint8_t *pData, uint32_t dataLen)
{
    return f_queue.add_frame(pData, dataLen);
}

int frame_get(uint8_t *pDataBuf, uint32_t *dataBufLen)
{
    return f_queue.get_frame(pDataBuf, dataBufLen);
}

