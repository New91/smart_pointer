#include<iostream>
#include "SmartPointer.hpp"
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
int main()
{
	
	test_smartpointer();

	return 0;
}