
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
protected:
	T* _ptr;
};