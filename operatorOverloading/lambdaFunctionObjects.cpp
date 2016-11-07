#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class StringSorter
{
public:
	StringSorter()
	{
		counter_ = 0;
	}
	~StringSorter(){}

	bool operator()(const std::string& prevString, const std::string& currString)
	{
		counter_++;
		//std::cout <<"String comparator called...." << counter_ << std::endl; 
		return prevString.size() < currString.size();
	}
private:
	unsigned int counter_;
};

class SizeCompare
{
public:
	SizeCompare(std::size_t stringLength) : stringLength_(stringLength){}
	~SizeCompare(){}
   
    bool operator()(const std::string& str)
    {
       return str.size() >= stringLength_;
    } 

private:
	std::size_t stringLength_;
};

int main()
{
	std::vector<std::string> words = {"The","girl","with","Dragon","Tatto"};
    std::vector<std::string> countries = \
    	{"Afghanistan","India","Israle","Czech Republic", "Poland", "Germany"};
	StringSorter sorter;
    std::stable_sort(words.begin(), words.end(), sorter);
    for(auto word: words)
    {
		std::cout << word << std::endl;
    }

    //sort by taking lambda function as the predicate
    //Lambda function used is equivalent to StringSorter function object class
    std:stable_sort(countries.begin(), countries.end(), \
    	[](const std::string& prevString, const std::string& currString)-> bool {
    		return prevString.size() < currString.size();
    });

    std::cout <<std::endl;
    for(auto country : countries)
    {
    	std::cout << country << std::endl;
    }

    std::size_t length = 4;
    SizeCompare comparator(length);
    auto iterToString = std::find_if(words.begin(), words.end(), comparator);
    std::cout <<"String with length 4 is : " << *iterToString << std::endl;

    //Using lambda function equivalent to SizeCompare function object class
    auto iter = std::find_if(countries.begin(), countries.end(), \
    	[length](const std::string& str)-> bool {
    		return str.size() >= length;
    });

    std::cout << "Country name with more than 4 letters is : " << *iter << std::endl;

    return 0;
}
