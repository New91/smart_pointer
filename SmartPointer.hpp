
template<class T>
class SmartPointer
{
public:
	SmartPointer(T* sp):_ptr(sp)
	{}

	~SmartPointer()
	{
		delete _ptr;
	}

	SmartPointer(SmartPointer<T>& other)
	{
		//管理权限转移，否则会造成重复释放的问题
		_ptr = other._ptr;
		other._ptr = NULL;
	}
	SmartPointer& operator=(SmartPointer<T>& other)
	{
		if (this != other)
		{
			//管理权限转移，否则会造成重复释放的问题
			_ptr = other._ptr;
			other._ptr = NULL;
		}

		return *this;
	}

	// 模拟普通指针的操作
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

protected:
	T* _ptr;
};