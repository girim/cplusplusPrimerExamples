#include "Blob.hpp"
#include "BlobPointer.hpp"

int main()
{
	Blob<std::string> blob;
	blob.push_back("C++");
	blob.push_back("Java");
	blob.push_back("Python");
	blob.push_back("JavaScript");
	blob.printContents();

 	Blob<int> intBlob;
 	intBlob.push_back(1);
 	intBlob.printContents();
    intBlob.pop_back();
    intBlob.pop_back();

    BlobPointer<std::string> blobPtr(blob);
    std::cout <<"Element is: " << *blobPtr << std::endl;
    ++blobPtr;

    std::cout <<"Element after ++: " << *blobPtr++ << std::endl;

    blobPtr--;
    std::cout <<"Element after ++: " << *++blobPtr << std::endl;

    --blobPtr;
    --blobPtr;
    --blobPtr;

    BlobPointer<std::string> blobPtr_1;
    ++blobPtr_1;

    Blob<int> blobInt = {1, 2, 3, 4};
    BlobPointer<int> blobPtrInt(blobInt);

    std::cout << "Number is : " << *blobPtrInt++ << std::endl;
    std::cout << "Number is : " << *blobPtrInt++ << std::endl;
    std::cout << "Number is : " << *blobPtrInt++ << std::endl;
    std::cout << "Number is : " << *blobPtrInt++ << std::endl;
    std::cout << "Number is : " << *--blobPtrInt << std::endl;
    std::cout << "Number is : " << *--blobPtrInt << std::endl;
    std::cout << "Number is : " << *--blobPtrInt << std::endl;
    std::cout << "Number is : " << *--blobPtrInt << std::endl;

	return 0;
}