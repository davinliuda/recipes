#ifndef __COMMON_CODEQUEUE_H__
#define __COMMON_CODEQUEUE_H__

#include<stdint.h>
#include <string.h>
class CShmMemory;

class CCodeQueue
{
public:

	enum
	{
		invalid_offset = -1, /**< ��Ч��ƫ���� */
		reserved_length = 8, /**< Ԥ���Ŀռ䳤��*/
	};

	/** �������õĹ����ڴ��� */
	static CShmMemory* m_pstSharedMemory;

	/** ���ö������ڵĹ����ڴ��� */
	static void set_sharedmemory(CShmMemory* pMem);

	/** �õ�������ռ�õ��ڴ��С*/
	static size_t size(int32_t buffersize);

protected://attributes
	//�������ܳ��ȣ���λ: Byte��
	int32_t m_iSize;
	//����������ʼλ��
	int32_t m_iHead;
	//�������ݽ���λ��
	int32_t m_iTail;
	//��������ƫ��λ��
	int32_t m_iCodeOffset;

public:
	CCodeQueue(int32_t size);
	~CCodeQueue();

	int32_t initialize(int32_t size);

	int32_t resume(int32_t size);

	void* operator new( size_t size ) throw();

	void  operator delete( void *pbuffer );

	/*
	* @method:    append ��β��׷����Ϣbuffer���ú���ֻ�Ǹı�m_iTail����ʹ���ڶ��̻߳�����Ҳ����Ҫ��/����������
	*				��Ϊ���������ֽڵ�int32_t�Ķ�д������ԭ�Ӳ���
	* @fullname:  Game51::Server::CCodeQueue::append
	* @access:    public 
	* @param: const char * code
	* @param: int32_t size
	* @return:   int32_t�� 
	* - 0: �ɹ�
	* - >0 : ʧ��
	* @qualifier: 
	* @note	
	* @par ʾ��:
	* @code
	
	* @endcode
	 
	* @see
	* @deprecated 
	*/
	int32_t append(const char* code, int32_t size);

	
	/*
	* @method:    pop �Ӷ���ͷ��ȡһ����Ϣ
	* @fullname:  Game51::Server::CCodeQueue::pop
	* @access:    public 
	* @param[in]: char * dst
	* @param[in,out]: short & outlength������dst�ĳ��ȣ�����ʵ����Ϣcode�ĳ���
	* @return:   int32_t
	* - 0: �ɹ�. outlength����ʵ��code�ĳ���
	* - >0 : ʧ�ܣ� dst,outlength��ֵ������
	* @qualifier:
	* @note	
	* @par ʾ��:
	* @code
	
	* @endcode
	 
	* @see
	* @deprecated 
	*/
	int32_t pop(char* dst, int32_t& outlength);



	/*
	* @method:    pop_from
	* @fullname:  Game51::Server::CCodeQueue::pop_from
	* @access:    public 
	* @param[in]: int32_t offset ָ����offset��ȡcode
	* @param[in]: int32_t codesize ָ����ȡ��code����
	* @param[in]: char * dst
	* @param[in,out]: int32_t & outlenght
	* @return:   int32_t
	* @qualifier:
	* @note	
	* @par ʾ��:
	* @code
	
	* @endcode
	 
	* @see
	* @deprecated  Ŀǰ��ʱ��ʵ�ָ÷�������Ϊ�ײ�Ϊ�����洢�Ķ�����ȡ���ݻ���������ƶ���Ч�ʽϵ͡�
	*/
	int32_t pop_from(int32_t offset, int32_t codesize, char* dst, int32_t& outlenght);


	
	/*
	* @method:    full �ж϶����Ƿ���
	* @fullname:  Game51::Server::CCodeQueue::full
	* @access:    public 
	* @param: void
	* @return:   bool
	* @qualifier:
	* @note	
	* @par ʾ��:
	* @code
	
	* @endcode
	 
	* @see
	* @deprecated 
	*/
	bool full(void);


	/*
	* @method:    empty �ж������Ƿ�Ϊ��
	* @fullname:  Game51::Server::CCodeQueue::empty
	* @access:    public 
	* @param: void
	* @return:   bool
	* @qualifier:
	* @note	
	* @par ʾ��:
	* @code
	
	* @endcode
	 
	* @see
	* @deprecated 
	*/
	bool empty(void);

protected:
	/** ����������ƫ�� */
	int32_t code_offset(void)const;

	int32_t set_boundary(int32_t head, int32_t tail);

	int32_t get_boundary(int32_t& head, int32_t& tail)const;

	char* get_codebuffer(void)const;

public:
	/*
	* @method:    get_freesize
	* @fullname:  Game51::Server::CCodeQueue::get_freesize
	* @access:    protected 
	* @param: void
	* @return:   int32_t
	* - ���ؿ��ÿռ�Ĵ�С�����û�п��ÿռ䣬����ֵΪ0��Ҳ����˵�ú�����
	*	����ֵ����>=0�ġ�
	* @qualifier: const
	* @note	��֤����buffer�ĳ��Ȳ���Ϊ0,������Ϊ����.
	* @par ʾ��:
	* @code
	
	* @endcode
	 
	* @see
	* @deprecated 
	*/
	int32_t get_freesize(void)const;

	int32_t get_codesize(void)const;

	
	

private:
	//forbidden copy constructor
	CCodeQueue(const CCodeQueue& init);
	CCodeQueue& operator =(const CCodeQueue&);
};



#endif /*__COMMON_CODEQUEUE_H__*/
