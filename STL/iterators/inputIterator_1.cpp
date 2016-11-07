#include <iostream>
#include <iterator>

//instream_iterator example for input iterator
int main(int argc, char const *argv[])
{
	typedef std::istream_iterator<int>::char_type CHR;
	typedef std::istream_iterator<int>::traits_type CHRT;

	std::cout << "enter intergers to read(enter any char to end) ....";
 
	std::istream_iterator<int, CHR, CHRT> iter(std::cin);
	std::istream_iterator<int, CHR, CHRT> endOfStream; //indicates the EOF

	while(iter != endOfStream)
	{
		std::cout << "read element is : " << *iter << std::endl;
		++iter;
	}
	
	return 0;
}