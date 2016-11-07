#include <iostream>
#include <map>
#include <functional>

class Triangle
{
public:
	Triangle(double base = 0, double height = 0) : \
		base_(base), height_(height){};

	double getAreaOfTriangle() const
	{
		return (0.5 * base_ * height_);
	}

	~Triangle(){};

private:
	double base_;
	double height_;
};

std::ostream& operator<<(std::ostream& os, const Triangle& tri)
{
	os << tri.getAreaOfTriangle();
	return os;
}

void drawDottedLine()
{
	std::cout << "-----------------------------" << std::endl;
}

template<typename T>
void print(const T& assoContainer, std::string name = "")
{
	drawDottedLine();
	std::cout <<"Displaying the contents of \"" << name << "\"" << std::endl;
	for (typename T::const_iterator iter = assoContainer.cbegin(); 
			iter != assoContainer.cend(); ++iter)
	{
		std::cout << "Key: " << iter->first << " Value: " << iter->second << std::endl;
	}
	drawDottedLine();
}

template<typename T>
void printReverse(const T& assoContainer, std::string name= "")
{
	drawDottedLine();
	std::cout <<"Displaying the contents from the end for \"" << name << std::endl;
	for(typename T::const_reverse_iterator iter =  assoContainer.crbegin(); \
		iter != assoContainer.crend();  ++iter)
	{
		std::cout << "Key: " << iter->first << " Value: " << iter->second << std::endl;
	}
	drawDottedLine();
}

int main(int argc, char const *argv[])
{
	std::map<int, char> firstMap;
	firstMap[4] = 'F';
	firstMap[1] = 'G';
	firstMap[6] = 'E';
	firstMap[3] = 'A';
	print(firstMap, "firstMap");

	std::map<int, char> secondMap(firstMap.begin(), firstMap.end());
	print(secondMap, "secondMap");

	std::map<int, char> thirdMap(secondMap);
	print(thirdMap, "thirdMap");

	std::map<std::string, int> countryList;
	countryList.insert({"China", 2});
	countryList.insert({"America", 1});
	countryList.insert({"Russia", 4});
	countryList.insert({"India", 3});
	print(countryList);

	Triangle t1(1, 3);
	Triangle t2(2, 9);
	Triangle t3(4, 8);
	Triangle t4(5, 1);
	std::function<bool(Triangle, Triangle)> comparable = [](const Triangle &lhs, const Triangle &rhs) {
		return (lhs.getAreaOfTriangle() < rhs.getAreaOfTriangle());
	};

	std::map<Triangle, int, decltype(comparable)> triangleList(comparable);
	triangleList.insert({t1, 1});
	triangleList.insert({t2, 2});
	triangleList.insert({t3, 3});
	triangleList.insert({t4, 4});

	print(triangleList);

	/*for(char ch = 'a'; ch <= 'z'; ch++)
		std::cout << ch;*/
	Triangle t5(8,1);
	triangleList.emplace(t5, 9);
	print(triangleList);
	printReverse(triangleList);

	auto iter = triangleList.find(t4);
	std::cout <<"Found element is : " << iter->first << std::endl;

	std::map<int, char>::iterator lowBoundIter = firstMap.lower_bound(6);
	std::map<int, char>::iterator upBoundIter = firstMap.upper_bound(6);

	std::cout << "Lower bound for 6 is: " << lowBoundIter->first << std::endl;
	std::cout << "Upper bound for 6 is: " << upBoundIter->first << std::endl;


	return 0;
}