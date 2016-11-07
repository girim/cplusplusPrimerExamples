#include <iostream>


int main()
{
	unsigned int UL = 1;
	unsigned long int quiz = 0;
	unsigned int number = 19;
 
    quiz |= (UL << 19);
    std::cout << "Setting 27th bit on: " << quiz << std::endl; 

    std::cout <<"inverting bits: " << ~number << std::endl;	
     
    quiz = quiz & ~(UL << 19);
    std::cout << "Setting 27th bit off: " << quiz << std::endl; 

	return 0;
}