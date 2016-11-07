#include <iostream>
void func(int &ref);
int add(int a, int b);
float add(int a, int b);

int main()
{
	int a = 10;
	int *ptr = &a;
 
    func(*ptr);

    std::cout << "ref: " << *ptr << std::endl;
    std::cout << "Sum: " << add(2, 4) << std::endl;
    std::cout << "Sum: " << add(10, 20) << std::endl;
}

void func(int &ref)
{
	std::cout <<"Ref : " << ref << std::endl;
	ref = 20;
}


int add(int a, int b)
{
	return (a+b);
}

float add(int a, int b)
{
	return (a+b);
}