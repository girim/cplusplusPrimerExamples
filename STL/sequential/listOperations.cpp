#include <iostream>
#include <list>

void drawDottedLine()
{
	std::cout << "-------------------------------" << std::endl;
}

template<typename T>
void printContents(const T& container, std::string name = "")
{
	std::cout << "Printing the contents of \""<< name << "\""<< std::endl;
	for(typename T::const_iterator iter = container.begin(); \
		iter != container.end(); ++iter)
	{
		std::cout << "Element is : " << *iter << std::endl;
	}
	drawDottedLine();
}

template<typename T>
void printContentsInReverse(const T& container, std::string name = "")
{
	std::cout << "Printing the contents in Reverse for \"" << name << "\""<< std::endl;
	for(typename T::const_reverse_iterator iter = container.crbegin(); \
		iter != container.crend(); ++iter)
	{
		std::cout << "Element is : " << *iter << std::endl;
	}
	drawDottedLine();
}

int main(int argc, char const *argv[])
{
	std::list<int> listOne(2, 7);
	printContents(listOne, "listOne");

	listOne.push_back(8);
	printContents(listOne, "listOne");

	listOne.push_front(6);
	printContents(listOne, "listOne");

	printContentsInReverse(listOne, "listOne");

	listOne.remove(7);
	printContents(listOne,"listOne");

	listOne.insert(++listOne.begin(), 4, 2);
	printContents(listOne);

	return 0;
}