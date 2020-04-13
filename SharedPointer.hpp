// �ο� https://www.cnblogs.com/yuwanxian/p/11042058.html
template<typename T>
class SharedPointer
{
private:
	// ��ʵ��ָ������ü�����װ����һ���ڲ�����
	struct  PtrCnt
	{
		PtrCnt(T* p) :m_pointer(p),m_refs(1){
		}
		~PtrCnt() {
			delete m_pointer;
		}
		T * m_pointer;
		size_t m_refs;
	};

	PtrCnt *m_ptr;

public:
	// ֻ����ʽ����
	explicit SharedPointer(T* p) :m_ptr(new PtrCnt(p)) {}
	~SharedPointer() {
		decrease();
	}

	SharedPointer(const SharedPointer& other) :m_ptr(other.m_ptr)
	{
		increase();
	}

	SharedPointer& operator=(const SharedPointer& other)
	{
		if (m_ptr != other.m_ptr)
		{
			decrease();//ԭ�ȵ����ü����ȼ�С
			m_ptr = other.m_ptr;
			increase();
		}
	}

	T* operator->() const {
		return m_ptr->m_pointer;
	}

	T& operator*()
	{
		return *(m_ptr->m_pointer);
	}


private:
	void decrease()
	{
		if (--(m_ptr->m_refs) == 0) {
			delete m_ptr;
		}
	}

	void increase()
	{
		++(m_ptr->m_refs);
	}
};
