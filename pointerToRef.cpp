#include <iostream>
void func(int &ref);

int main()
{
	int a = 10;
	int *ptr = &a;
 
    func(*ptr);

    std::cout << "ref: " << *ptr << std::endl;
}

void func(int &ref)
{
	std::cout <<"Ref : " << ref << std::endl;
	ref = 20;
}