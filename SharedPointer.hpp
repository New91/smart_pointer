// 参考 https://www.cnblogs.com/yuwanxian/p/11042058.html
template<typename T>
class SharedPointer
{
private:
	// 把实际指针和引用计数封装到了一个内部类中
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
	// 只能显式构造
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
			decrease();//原先的引用计数先减小
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
