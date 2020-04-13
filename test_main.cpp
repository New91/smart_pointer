#include<iostream>
#include "SmartPointer.hpp"
using namespace std;

class Demo {
public:
	Demo(int d) :data(d) {}
private:
	int data;
};

int test_smartpointer() {
	SmartPointer<Demo> pdemo(new Demo(100));
	return 0;
}
int main()
{
	
	test_smartpointer();

	return 0;
}