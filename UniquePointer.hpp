// 与 std::unique_ptr 大致思路
// 默认删除器
template<typename T>
struct DefaultDeleter
{
	void operator () (T *p)
	{
		if (p) {
			delete p;
			p = nullptr;
		}
	}
};

template<typename T, typename Del = DefaultDeleter<T> >
class UniquePointer
{
public:
	UniquePointer(T *pt = nullptr):m_ptr(pt)
	{

	}

	~UniquePointer()
	{
		del();
	}

private:
	// 不允许拷贝
	UniquePointer(const UniquePointer &);
	UniquePointer& operator=(const UniquePointer &) {

	}
	void del()
	{
		if (*this)
		{
			m_deleter(m_ptr);
			m_ptr = nullptr;
		}
	}
public:
	void reset(T *p)
	{
		del();
		m_ptr = p;
	}

	T* release() {
		T *p = m_ptr;
		m_ptr = nullptr;
		return p;
	}

	T* get()
	{
		return m_ptr;
	}

	operator bool() const {
		return nullptr != this;
	}

	T& operator*()
	{
		return *m_ptr;
	}

	T* operator->()
	{
		return m_ptr;
	}

private:
	T *m_ptr;
	Del m_deleter;
};