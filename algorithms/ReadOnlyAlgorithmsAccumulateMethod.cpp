#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	//Read-only Alogorithms
	//Ex: accumulate(startIterator, endIterator, initialValue);
	vector<int> evenNumbers = { 2,4,6,8,10,12,24,26,28 };
	auto sumOfEvenNumbers = accumulate(evenNumbers.cbegin(), evenNumbers.cend(), 0);

	cout << "Sum of even numbers is : " << sumOfEvenNumbers << endl;

	list<string> name = { "Stanly ","B"," Lipmen" };
	auto fullName = accumulate(name.cbegin(), name.cend(), string("")); 
	//auto fullName = accumulate(name.cbegin(), name.cend(), "");   
	//--> Passing empty string as string literal gives a compile-time error
	//Also you cannot pass 'const char*' type strings
	                                                                    
	cout << "Full name is : " << fullName << endl;

	return 0;
}


