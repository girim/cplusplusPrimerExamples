#include "strBlob.hpp"
#include <iostream>

int main()
{
	StrBlob blob;
	blob.push_back("Hi");
	blob.push_back("Hello");
	blob.push_back("Bonsoir");

	blob.printElements();
    std::cout << "Front: " << blob.front() << std::endl;
    std::cout << "Back: " << blob.back() << std::endl;
 
    StrBlob blobCopy = blob;
    blobCopy.pop_back();

    std::cout << std::endl;
    blob.printElements();
    blobCopy.printElements();

	return 0;
}