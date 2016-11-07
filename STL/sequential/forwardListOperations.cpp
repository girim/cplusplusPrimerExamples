#include <iostream>
#include <forward_list>

void drawDottedLine()
{
	std::cout << "-------------------------------" << std::endl;
}

template<typename T>
void print(const T& container, std::string name="")
{
	drawDottedLine();
	std::cout << "Printing contents of : \"" << name << "\"" << std::endl;
	for(typename T::const_iterator iter = container.begin(); \
			iter != container.end(); ++iter)
	{
		std::cout << "Element is : " << *iter << std::endl;
	}
	drawDottedLine();
}

int main(int argc, char const *argv[])
{
	std::forward_list<int> flist;
	flist.insert_after(flist.before_begin(), {1,2,3,4});
	print(flist);

	flist.push_front(8);
	print(flist);

	flist.emplace_front(7);
	print(flist);

	auto iter = flist.emplace_after(++flist.before_begin(), 6);
	print(flist);

	iter = flist.emplace_after(iter, 4);
	print(flist);

	flist.sort();
	print(flist);

	flist.reverse();
	print(flist);

	flist.unique();
	print(flist);

	std::forward_list<int> first = {1,2,3,4};
	std::forward_list<int> second = {5, 6, 7};
	second.merge(first, std::greater<int>());
	print(first, "first");
	print(second, "second");

	return 0;
}