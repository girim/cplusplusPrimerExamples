#include <iostream>
#include <unordered_set>
#include <functional>
#include <string>

struct StringHashBySize
{
	public:
		std::size_t operator()(const std::string& str) const
		{
			return std::hash<int>()(str.length());
		}
};


struct StringEqualBySize
{
	public:
		bool operator()(const std::string& lhs, const std::string& rhs) const
		{
			return (lhs.length() == rhs.length());
		}
};

void drawdottedline()
{
	std::cout << "-----------------------------" << std::endl;
}

template<typename T>
void print(const T& container, std::string msg = "")
{
	drawdottedline();
	for(typename T::const_iterator iter = container.cbegin(); \
			iter != container.cend(); ++iter)
	{
		std::cout << "element is : " << *iter << std::endl;
	}
	drawdottedline();
}


int main(int argc, char const *argv[])
{
	std::unordered_set<std::string, StringHashBySize, StringEqualBySize> names;
	names.insert("India");
	names.insert("aidnI");
	names.insert("Japan");
	names.insert("Israle");
	print(names);

	/*std::function<bool(std::string, std::string)> comparable = [](const std::string& lhs, const std::string& rhs){
		return (lhs.length() == rhs.length());
	};

	std::unordered_set<std::string, StringEqualBySize, comparable> list;*/

	return 0;
}