#include <iostream>
#include <unordered_set>
#include <string>
#include <functional>

void drawdottedline()
{
	std::cout << "---------------------------" << std::endl;
}

template<typename T>
void print(const T& container, std::string name="")
{
	drawdottedline();
	std::cout << "contents of \"" << name << "\" are: " << std::endl;
	for(typename T::const_iterator iter = container.cbegin(); \
			iter != container.cend(); ++iter)
	{
		std::cout <<"element is : " << *iter << std::endl;
	}
	drawdottedline();
}

int main(int argc, char const *argv[])
{
	//using copy constructor
	std::unordered_set<int> firstSet = {44, 22, 11, 33};
	print(firstSet, "firstSet");

	//using copy constructor
	std::unordered_set<int> secondSet(firstSet);
	print(secondSet, "secondSet");

	firstSet.insert({1, 4, 7});
	print(firstSet);

	//using range iterators
	std::unordered_set<int> thirdSet(secondSet.begin(), secondSet.end());
	print(thirdSet, "thirdSet");

	/*Element lookup*/
	std::unordered_set<int>::iterator iter  = firstSet.find(22);
	std::cout << "Found item is : " << *iter << std::endl;
	iter = firstSet.find(55);
	if(iter == firstSet.end())
		std::cout << "Element not found ...." << std::endl;

	std::cout << "Element count for  44 is: " << firstSet.count(44) << std::endl;
	std::cout << "Element count for  55 is: " << firstSet.count(55) << std::endl;

	std::pair<std::unordered_set<int>::iterator, std::unordered_set<int>::iterator> range =
		firstSet.equal_range(22);

	std::cout << "Lower bound: " << *(range.first) << std::endl;
	std::cout << "Upper bound: " << *(range.second) << std::endl;

	/*Modifiers*/
	auto it = firstSet.erase(firstSet.begin()); //erase using iterator 
	std::cout << "Iter after ereasing first element is : " << *it << std::endl;
	print(firstSet);

	auto noOfElementsErased = firstSet.erase(11);
	std::cout <<"Number of elements erased  : " << noOfElementsErased << std::endl;
	print(firstSet);

	it = firstSet.erase(++it, firstSet.end());//using range iterator
	print(firstSet,"firstSet");

	/*Buckets*/
	std::unordered_set<std::string> planets = {"Mercury", "Venus", "Earth", "Mars", \
												"Jupitor", "Saturn", "Uranus", "Neptune", "Pluto"};

	unsigned totalBuckets = planets.bucket_count();
	std::cout << "Number of Buckets : " << totalBuckets << std::endl;


	for(auto bucketNum = 0; bucketNum < totalBuckets; ++bucketNum)
	{
		std::cout << "Bucket #" << bucketNum << " has " << planets.bucket_size(bucketNum) << " ";
		std::cout << "{";
		for(auto iter = planets.begin(bucketNum); iter != planets.end(bucketNum);  ++iter)
		{
			std::cout << *iter << " ";
		}
		std::cout << "}" << std::endl;
	}

	drawdottedline();
	for(auto planet: planets)
	{
		std::cout << "Planet " << planet << " is in Bucket #" << planets.bucket(planet) << std::endl;
	}


	return 0;
};
