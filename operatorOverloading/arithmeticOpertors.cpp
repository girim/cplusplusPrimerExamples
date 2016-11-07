#include <iostream>
#include <string>
#include <cctype>

void convertStringToUpperCase(std::string &text);

void convertStringToUpperCase(std::string &text)
{
	for(auto it = text.begin(); it != text.end() && !isspace(*it); ++it)
    {
    	*it = toupper(*it);
    }

    std::cout <<"Saying " << text << std::endl;
}

int main()
{
	int variable_1 = 0;
	int variable_2 = 0;

	//prefix operators increments the object value and then returns the object as 'lvalue'
    std::cout << "Value after prefix increament: " << ++variable_1 << std::endl;

    //postfix operators returns the copy of the object before increamenting the object as 'rvalue'
    std::cout << "Value after postfix increament: " << variable_2++ << std::endl;

    std::string sayHello = "hello";
    convertStringToUpperCase(sayHello);

    std::string sayGoodBye = "goodbye";

   	auto it = sayGoodBye.begin();
    while(it != sayGoodBye.end() && !isspace(*it))
    { 
 		*it = toupper(*it++);
    }
    std::cout <<"Saying " << sayGoodBye << std::endl;

	return 0;
}