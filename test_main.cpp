#include<iostream>
#include "SmartPointer.hpp"
#include "UniquePointer.hpp"
using namespace std;

class Demo {
public:
	Demo(int d) :data(d) {}
	int func() {
		cout << __FUNCTION__ << endl;
		return 0;
	}
private:
	int data;
};

int test_smartpointer() {
	SmartPointer<Demo> pdemo(new Demo(100));
	SmartPointer<Demo> pdemo2 = pdemo;
	pdemo2->func();
	(*pdemo2).func();
	
	return 0;
}
int test_uniquepointer()
{
	UniquePointer<Demo> pdemo(new Demo(100));
	// 权限不可转移
	//UniquePointer<Demo> pdemo2 = pdemo;
	//UniquePointer<Demo> pdemo2(pdemo);
	pdemo->func();
	(*pdemo).func();
	return 0;
}
int main()
{
	
	test_smartpointer();
	test_uniquepointer();
	return 0;
}