#include "common_codequeue.h"
#include "common_memory.h"
#include"common.h"

#include<iostream>
using namespace std;

CShmMemory* CCodeQueue::m_pstSharedMemory = NULL;

void CCodeQueue::set_sharedmemory(CShmMemory* pMem)
{
	m_pstSharedMemory = pMem;
}

size_t CCodeQueue::size(int32_t buffersize)
{
	size_t itotal = sizeof(CCodeQueue);
	if (buffersize > 0)
	{
		itotal += buffersize;
	}

	return itotal;
}

CCodeQueue::CCodeQueue(int32_t size)
{
	if (NULL == m_pstSharedMemory)
	{
		m_iSize = 0;
		m_iHead = 0;
		m_iTail = 0;
		m_iCodeOffset = invalid_offset;
	}

	//shm_mode_init mode
	if (CShmMemory::shm_mode_init == m_pstSharedMemory->get_mode())
	{
		cout<<"hell"<<endl;
		initialize(size);
	}
	else//resume
	{
		resume(size);
	}
}

CCodeQueue::~CCodeQueue()
{

}

int32_t CCodeQueue::initialize(int32_t size)
{
	char* code_zone = (char*)m_pstSharedMemory->create_segment(size);
	if (NULL == code_zone)
	{
		return fail;
	}

	m_iCodeOffset = int32_t(code_zone - (char*)this);
	m_iSize = size; //���������õ��ܳ���
	m_iHead = 0;
	m_iTail = 0;

	return success;
}

int32_t CCodeQueue::resume(int32_t size)
{
	if (NULL == m_pstSharedMemory)
	{
		return fail;
	}

	m_pstSharedMemory->create_segment(size);

	return success;
}

void* CCodeQueue::operator new(size_t size)throw()
{
	if (NULL == m_pstSharedMemory)
	{
		return NULL;
	}
	
	//ΪCCodeQueue�����������ռ�
	return (void*)(m_pstSharedMemory->create_segment((int32_t)size));
}

void CCodeQueue::operator delete(void *pbuffer)
{
	//do nothing,here!
}

int32_t CCodeQueue::append(const char *code, int32_t size)
{
	if (invalid_offset == code_offset() || m_iSize <= 0)
	{
		cout<<"aaaaaaaaaaaaaaaaa"<<endl;	
		return fail;
	}

	if (full())
	{
		cout<<"bbbbbbbbbbbbbbbbb"<<endl;
		return queue_buffer_is_not_enough;
	}

	int32_t head = 0;
	int32_t tail = 0;

	get_boundary(head, tail);
	if (head < 0 || head >= m_iSize || tail < 0 || tail >= m_iSize)
	{
		//�����������ж����е�����
		head = tail = 0;
		set_boundary(head, tail);

		cout<<"cccccccccccccccc"<<endl;
		return fail;
	}

	int32_t free_size = get_freesize();

	//ÿ����Ϣcode����ǰ��4ByteΪ��Ϣcode�ĳ���(��������4��Byte)
	//pop()������ҲĬ����һ����
	if ((int32_t)sizeof(int32_t) + size > free_size)
	{
		cout<<"ddddddddddddddddddd"<<endl;
		return queue_buffer_is_not_enough;
	}

	char* pszDst = get_codebuffer();
	char* pszSrc = (char*)&size;

	for (size_t i = 0; i < sizeof(int32_t); ++i)
	{
		pszDst[tail] = pszSrc[i];
		tail = (tail + 1)%m_iSize;  //ע�⣺��֤m_iSize����Ϊ0!!
	}

	if (head > tail)//
	{
		memcpy(&pszDst[tail], (const void*)code, (size_t)size);
	}
	else
	{
		if (size > (m_iSize - tail))
		{
			//��Ҫ�ֶο���
			memcpy(&pszDst[tail], (const void*)code, (size_t)(m_iSize - tail));
			memcpy(&pszDst[0], (const void*)(code + (m_iSize-tail)), (size_t)(size - (m_iSize - tail)));
		}
		else
		{
			memcpy(&pszDst[tail], (const void*)code, (size_t)size);
		}
	}

	tail = (tail + size)%m_iSize;

	//������m_iTail
	set_boundary(-1, tail);

	return success;
}

int32_t CCodeQueue::pop(char *dst, int32_t &outlength)
{
	if (NULL == dst || 0 >= outlength)
	{
		return fail;
	}
	
	if (invalid_offset == code_offset() || m_iSize <= 0)
	{
		return fail;
	}

	if (empty())
	{
		return queue_is_empty;
	}

	int32_t code_size = get_codesize();

	int32_t head = 0;
	int32_t tail = 0;

	get_boundary(head, tail);
	
	//���code����4��Byte,��ζ�Ŷ�����
	if (code_size < (int32_t)sizeof(int32_t))
	{
		//�Ѷ������
		outlength = 0;
		head = tail = 0;
		set_boundary(head, tail);
		return fail;
	}

	//Ԥ�ȱ������buffer�Ĵ�С
	int32_t buffer_size = outlength;

	//ʹ��real_outlength����ʵ��code�ĳ���
	int32_t real_outlength = 0;
	char* pszDst = (char*)&real_outlength;

	char* code_zone = get_codebuffer();
	if (NULL == code_zone)
	{
		return fail;
	}

	//����ȡcode�ĳ���(Ҳ����ǰ4Byte)
	for (size_t i = 0; i < sizeof(int32_t); ++i)
	{
		pszDst[i] = code_zone[head];
		head = (head+1)%m_iSize;
	}

	//����Ӷ����ж�ȡ��code���Ȳ�����Ҫ��
	if (real_outlength <= 0 || real_outlength > (code_size - (int32_t)sizeof(int32_t)))
	{
		outlength = 0;
		head = tail = 0;
		set_boundary(head, tail);
		return fail;
	}

	//���buffer����
	if (buffer_size < real_outlength)
	{
		//added by aprilliu, 2008-09-16
		//�����Ƿ���.���������Ƿ��׵�? real_outlength�ĸ��ֽڵĳ�����connectorsvrd����
		//Ӧ���ǿ��ŵ�
		head = (head+real_outlength)%m_iSize;
		set_boundary(head, -1);//������headָ��
		return fail;
	}

	//copy code buffer
	outlength = real_outlength;
	pszDst = dst;

	if (tail > head)
	{
		memcpy(pszDst, (const void*)&code_zone[head], (size_t)outlength);
	}
	else
	{
		//�����ǰcode���ֶַ�
		if (outlength > (m_iSize - head))
		{
			memcpy(dst, (const void*)&code_zone[head], (size_t)(m_iSize - head));
			memcpy((void*)&dst[m_iSize-head], (const void*)&code_zone[0], size_t(outlength-(m_iSize-head)));
		} 
		else
		{
			memcpy(dst, (const void*)&code_zone[head], size_t(outlength));
		}

	}//else

	//�ƶ�ͷָ��
	head = (head+outlength)%m_iSize;
	set_boundary(head, -1);//������headָ��

	return success;
}

int32_t CCodeQueue::pop_from(int32_t offset, int32_t codesize, char *dst, int32_t &outlenght)
{
	//TODO ����Ч�ʵĿ��ǣ��ݲ�ʵ�ָú�����ֱ�ӷ��ش���
	return fail;

}

bool CCodeQueue::full()
{
	return!(get_freesize() > 0);
}

//��Ʊ�֤m_iHead��m_iTailֻ���ڶ���Ϊ�յ�ʱ��������
bool CCodeQueue::empty()
{
	return(m_iHead == m_iTail);
}

int32_t CCodeQueue::code_offset() const
{
	return m_iCodeOffset;
}

int32_t CCodeQueue::set_boundary(int32_t head, int32_t tail)
{
	if (head >= 0 && head < m_iSize)
	{
		m_iHead = head;
	}
	
	if (tail >= 0 && tail < m_iSize)
	{
		m_iTail = tail;
	}
	
	return 0;
}

/**���ڶ�4Byte��int32_t���еĶ�д��������ԭ���Եģ����Լ�ʹ���ڶ��̻߳�����Ҳ����Ҫ��/��������*/
int32_t CCodeQueue::get_boundary(int32_t &head, int32_t &tail)const
{

	head = m_iHead;
	tail = m_iTail;
	return 0;
}

int32_t CCodeQueue::get_freesize(void)const
{
	int32_t head = 0;
	int32_t tail = 0;

	get_boundary(head, tail);

	int32_t free_size = 0;

	if (head == tail)//�ն���
	{
		free_size = m_iSize;
	}
	else if (head > tail)
	{
		free_size = head - tail;
	} 
	else
	{
		free_size = head + (m_iSize - tail);
	}

	//ȥ��Ԥ���Ŀռ�
	free_size -= reserved_length;
	if (free_size < 0)
	{
		free_size = 0;
	}

	return free_size;
}

int32_t CCodeQueue::get_codesize(void) const
{
	//����get_freesize�ķ���ֵ����>=0(������ָ�ֵ)�����Ըú��������Ĵ�������ȷ��
	return (m_iSize - get_freesize() - reserved_length);
}

char* CCodeQueue::get_codebuffer() const
{
	return((m_iCodeOffset != invalid_offset)? (char*)((char*)this + m_iCodeOffset) : NULL);
}

