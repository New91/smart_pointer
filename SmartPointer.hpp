
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
		//����Ȩ��ת�ƣ����������ظ��ͷŵ�����
		_ptr = other._ptr;
		other._ptr = NULL;
	}
	SmartPointer& operator=(SmartPointer<T>& other)
	{
		if (this != other)
		{
			//����Ȩ��ת�ƣ����������ظ��ͷŵ�����
			_ptr = other._ptr;
			other._ptr = NULL;
		}

		return *this;
	}

	// ģ����ָͨ��Ĳ���
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