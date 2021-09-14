#ifndef __COMMON_MEMEORY_H__
#define __COMMON_MEMEORY_H__


#include<stdint.h>
#include<string.h>
#include<time.h>
#include <sys/ipc.h>

       #include <sys/shm.h>

class CShmMemory
{
public:
	enum 
	{
		shm_mode_resume = 0,
		shm_mode_init = 1

	};
public:
	static char* m_pszShmMemory;
protected:
	//�����ڴ��
	key_t	m_unShmKey;

	//�ڴ��ܴ�С
	size_t	m_iShmSize;
	
	//�ڴ�ͷУ���
	uint32_t m_unCRC;

	//�ڴ洴��ʱ��
	time_t	m_tmCreateTime;

	//������ʱ��
	time_t	m_tmLastTimeStamp;

	//�����ڴ�
	char*	m_pszAvailableShm;
	//�ڴ�ʹ��ģʽ
	int32_t		m_iShmMode;
public:
	CShmMemory();
	CShmMemory(key_t unKey, size_t size);
	CShmMemory(key_t unKey, size_t iSize, int32_t iInitFlag );
	~CShmMemory();

	//��ʱ�������ֹ�ڴ�ʧЧ	
	void set_time_stamp();

	void* operator new(size_t iSize) throw();

	void  operator delete(void *pMemory);

	int32_t get_mode();
	
	//�����СΪiSize���ڴ�飬ʧ�ܷ���NULL
	void*  create_segment(size_t iSize);
	
	//�õ����ÿռ��С����λ:Byte
	size_t	get_free_size();

	//�õ����ÿռ��С����λ:Byte
	size_t get_used_size();

protected:

	//int32_t Initialize(key_t unKey, size_t iSize, int32_t iInitFlag = 0);
	int32_t Initialize(key_t unKey, size_t iSize);
private:
};

//���������ڴ�
CShmMemory* create_shm_memory(key_t unKey, size_t iSize, int32_t iInitFlag = 0);

//���չ����ڴ�
int32_t destroy_shm_memory(key_t unKey);

#endif
