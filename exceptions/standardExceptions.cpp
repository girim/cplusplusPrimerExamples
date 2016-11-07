#include <iostream>
#include <exception>
#include <memory>
#include <typeinfo>
#include <functional>

class BaseClass 
{
	public:
		virtual void member()
		{
			/*Do nothing*/
		}
};

class DerivedClass : BaseClass
{
	
};

int main()
{
	//standard library errors are
	/*1. bad_alloc
	  2. bad_cast
	  3. bad_exception
	  4. bad_typeid
	  5. bad_function_call
	  6. bad_weak_ptr*/
    
    /*1. bad_alloc*/
    int *ptr = nullptr;
    try
    {
    	ptr = new int[10];
    }
    catch(std::bad_alloc &error)
    {
    	std::cout << "Exception caught: " << error.what() << std::endl;
    }

    delete [] ptr;



    /*2. bad_cast*/
    try
    {
	    BaseClass baseClass;
    	DerivedClass &derivedClass = dynamic_cast<DerivedClass&>(baseClass); //throws std::bad_cast exception
    }
    catch(std::bad_cast &error)
    {
    	std::cout << "Exception caught: " << error.what() << std::endl;
    }

    /*3. bad_typeid*/
    try
    {
    	BaseClass *baseClass = nullptr;
    	std::cout << "TypeId of baseClass is: " << typeid(*baseClass).name() << std::endl;
    }
    catch(std::bad_typeid &error)
    {
    	std::cout << "Exception caught: " << error.what() << std::endl;
    }

    std::function<int(int, int)> add = std::plus<int>();
    std::function<int(int, int)> sub = 0;

    /*4. bad_function_call*/
    try
    {
    	std::cout << add(10,20) << std::endl;
    	std::cout << sub(20,10) << std::endl;
    }
    catch(std::bad_function_call &error)
    {
    	std::cout << "Exception caught: " << error.what() << std::endl;
    }

	return 0;
}