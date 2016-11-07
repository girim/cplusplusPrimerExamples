#include <iostream>

template<typename T>
class Array
{
public:
	Array(T array[], std::size_t length = 0);
	~Array();
	void print();

private:
	T *ptrToArrayElements_;
	std::size_t size_;
};

template<typename T>
Array<T>::Array(T array[], std::size_t length) : size_(length)
{
	ptrToArrayElements_ = new T[length];
	for(std::size_t index = 0; index < length; index++)
	{
		ptrToArrayElements_[index] = array[index];
	}
}

template<typename T>
Array<T>::~Array()
{
	delete [] ptrToArrayElements_;
	std::cout << "Class destroyed...." << std::endl;
}


template<typename T>
void Array<T>::print()
{
	for(std::size_t index = 0; index < size_;  ++index)
	{
		std::cout <<"Element is : " << *(ptrToArrayElements_ + index) << std::endl;
	}
}

int main()
{
	int arr[] = {1,2,3,4};
	Array<int>  customArray(arr, 4);
	customArray.print();

	return 0;
}