#ifndef librtmp_send264_H_
#define librtmp_send264_H_

#ifdef __cplusplus
extern "C"{
#endif  
 
/**
 * ��ʼ�������ӵ�������
 *
 * @param url �������϶�Ӧwebapp�ĵ�ַ
 *					
 * @�ɹ��򷵻�1 , ʧ���򷵻�0
 */ 
int RTMP264_Connect(const char* url);    
    
/**
 * ���ڴ��е�һ��H.264�������Ƶ��������RTMPЭ�鷢�͵�������
 *
 * @param read_buffer �ص������������ݲ����ʱ��ϵͳ���Զ����øú�����ȡ�������ݡ�
 *					2���������ܣ�
 *					uint8_t *buf���ⲿ���������õ�ַ
 *					int buf_size���ⲿ���ݴ�С
 *					����ֵ���ɹ���ȡ���ڴ��С
 * @�ɹ��򷵻�1 , ʧ���򷵻�0
 */ 
int RTMP264_Send(int (*read_buffer)(unsigned char *buf, int buf_size));

/**
 * �Ͽ����ӣ��ͷ���ص���Դ��
 *
 */    
void RTMP264_Close();  

#ifdef __cplusplus
}
#endif  

#endif