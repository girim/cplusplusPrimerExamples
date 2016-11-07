#include <iostream>
#include <vector>

void printVectorContents(const std::vector<int> &vec)
{
	//using const_iterator
	for(std::vector<int>::const_iterator iter = vec.cbegin(); iter != vec.cend(); ++iter)
		std::cout << "Element is (const): " << *iter << std::endl;

	//Below code also works if we use .begin() instead of .cbegin()
	/*for(std::vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
		std::cout << "Element is (const): " << *iter << std::endl;*/

	//Do not work cannot assing 'const' iterator to non-const type
	/*for(std::vector<int>::iterator iter = vec.cbegin(); iter != vec.cend(); ++iter)
		std::cout << "Element is (const): " << *iter << std::endl;*/
}

void printVectorContents(std::vector<int> &vec)
{
	//using non-const iterator
	for(std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
		std::cout << "Element is (non-const): " << *iter << std::endl;
}

int main()
{
	/*6 Ways of initializing vectors*/
	std::vector<int> numbers;                                 //1. empty vectors
	std::vector<int> zeros(8, 0);                            //2. Initialize vector with 8 elements with value of each as '0'.
	std::vector<int> twinOfZeros(zeros.begin(), zeros.end()); //3. Using the range constuctor
	std::vector<int> copyOfZeros(zeros);                      //4. Using copy constuctor
	const std::vector<int> primeNumbers = {1, 3, 5, 7, 11};   //5. Using initializer_list

	std::cout << "Is numbers empty: " << (numbers.empty() ? "yes" :  "no") << std::endl;

	std::cout << "Contents of the vector zeros is : " << std::endl;
	printVectorContents(zeros);

	std::cout << "Contents of the vector primeNumbers is: " << std::endl;
	printVectorContents(primeNumbers);

	int oddNumbers [] = {1, 3, 5, 7};
	std::vector<int> createdFromArray(oddNumbers, (oddNumbers + sizeof(oddNumbers) /sizeof(int)));
	printVectorContents(createdFromArray);


	return 0;
}