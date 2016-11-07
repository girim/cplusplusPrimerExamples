#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <functional>

void drawDottedLine()
{
	std::cout << "--------------------------------" << std::endl;
}

template<typename UM>
void print(const UM& container, std::string name = "")
{
	drawDottedLine();
	std::cout << "Contents of \"" << name  << "\" are: " << std::endl;
	for(typename UM::const_iterator iter = container.cbegin(); \
			iter != container.cend(); ++iter)
	{
		std::cout << "Key: " << iter->first << " Value: " << iter->second << std::endl;
	}
	drawDottedLine();
}

class Rhombus
{
public:
	Rhombus(double lengthOfSides = 0, double altitude = 0, \
		double diagonalP = 0, double diagonalQ = 0): lengthOfSides_(lengthOfSides), altitude_(altitude), \
			diagonalP_(diagonalP), diagonalQ_(diagonalQ) {};
	~Rhombus(){};

	double getArea() const
	{
		return altitude_ * lengthOfSides_;
	}

	double getLengthOfSides() const { return lengthOfSides_; }
	double getAltitude() const { return altitude_; }
	double getDiagonalP() const { return diagonalP_; }
	double getDiagonalQ() const { return diagonalQ_; }

private:
	double lengthOfSides_;
	double altitude_;
	double diagonalP_;
	double diagonalQ_;
};

std::ostream& operator<<(std::ostream& os, const Rhombus& rhombus)
{
	os  << "{ side: " << rhombus.getLengthOfSides() \
		<< ", altitude: " <<rhombus.getAltitude() \
		<< ", diagonalP: "<< rhombus.getDiagonalP() \
		<< ", diagonalQ: " << rhombus.getDiagonalQ() \
		<< ", Area: " << rhombus.getArea() \
		<< " }" << std::endl;

	return os;
}

int main(int argc, char const *argv[])
{
	//Using list initialization
	std::unordered_map<int, std::string> firstMap = {{4, "India"}, 
													{3, "China"},
													{2, "America"},
													{1, "Japan"}};
	print(firstMap, "firstMap");
	std::unordered_map<int, std::string> secondMap(firstMap.begin(), firstMap.end());
	print(secondMap, "secondMap");

	std::pair<int, char> p1 = std::make_pair(10, 'A');
	std::pair<int, char> p2 = std::make_pair(30, 'B');
	std::pair<int, char> p3 = std::make_pair(40, 'C');
	std::pair<int, char> p4 = {50, 'D'};

	std::unordered_map<int, char> thirdMap;
	thirdMap.insert(p1);
	thirdMap.insert(p2);
	thirdMap.insert(p3);
	thirdMap.insert(p4);
	print(thirdMap);


	std::cout << "Element at 30 is : " << thirdMap.at(30) << std::endl;

	std::cout << "bucket number for 1 is : " << firstMap.bucket(1) << std::endl;
	std::cout << "bucket number for 3 is : " << firstMap.bucket(3) << std::endl;
	std::cout << "bucket number for 4 is : " << firstMap.bucket(4) << std::endl;
	std::cout << "bucket number for 2 is : " << firstMap.bucket(2) << std::endl;
	std::cout << "bucket count for thirdMap is: " << firstMap.bucket_count() << std::endl;

	for(int bucket = 0; bucket < firstMap.bucket_count(); ++bucket)
	{
		std::cout << "Bucket number : " << bucket << " has " << firstMap.bucket_size(bucket) \
			<< " elements...." << std::endl;
	}

	std::cout << "bucket number for p1 is #" << thirdMap.bucket(10) << std::endl;
	std::cout << "bucket number for p2 is #" << thirdMap.bucket(30) << std::endl;
	std::cout << "bucket number for p3 is #" << thirdMap.bucket(40) << std::endl;
	std::cout << "bucket number for p4 is #" << thirdMap.bucket(50) << std::endl;

	for(int bucket = 0; bucket < thirdMap.bucket_count(); ++bucket)
	{
		std::cout << "Bucket number: " << bucket << " has " << thirdMap.bucket_size(bucket) \
			<< " elements...." << std::endl;
	}


	//How to find and element exists in map or not
	if(!firstMap.count(5)) //count returns '0' if key is not found
	{
		std::cout << "Element not found ...." << std::endl; 
	}

	try{
		firstMap.at(5); //at returns ref to element if key is found else throws std::out_of_range exception
	}
	catch(std::out_of_range &err)
	{
		std::cout << "Element not found ..." << std::endl;
		std::cout << err.what() << std::endl;
	}

	Rhombus r1(6, 8, 9, 9);
	Rhombus r2(5, 4, 3, 3);
    Rhombus r3(1, 2, 7, 7);
	std::unordered_map<std::string, Rhombus> userDefinedType;
	userDefinedType.insert({"R1", r1});
	userDefinedType.emplace("R2", r2);
	userDefinedType.insert({"R3", r3});
	print(userDefinedType, "userDefinedType");


	/*Using Rhombus as the key:*/
/*	Rhombus r3(1,2,7,7);
	std::function<bool(Rhombus, Rhombus)> comp = [](const Rhombus &lhs, const Rhombus &rhs){
		return (lhs.getArea() < rhs.getArea());
	};

	std::unordered_map<Rhombus, std::string, decltype(comp)> rhombusList;
	rhombusList.insert(r2, "B");
	rhombusList.insert(r3, "C");
	auto iter =  rhombusList.find(r2);*/

	std::unordered_map<std::string, Rhombus>::hasher fn = userDefinedType.hash_function();
	std::cout << "hash# for R1 is: " << fn("R1") << std::endl; 
	std::cout << "hash# for R2 is: " << fn("R2") << std::endl; 
	std::cout << "hash# for R3 is: " << fn("R3") << std::endl; 
	std::cout << "hash# for empty string ..." << fn("") << std::endl;

	std::unordered_map<int, char>::hasher hfn = thirdMap.hash_function();
	std::cout << "hash for 10 is : " << hfn(10) << std::endl;
	std::cout << "hash for 30 is : " << hfn(30) << std::endl;
	std::cout << "hash for 40 is : " << hfn(40) << std::endl;
	std::cout << "hash for 50 is : " << hfn(50) << std::endl;

	return 0;
}