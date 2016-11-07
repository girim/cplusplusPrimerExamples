#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void printResults(vector<int>::const_iterator iteratorToTheNumberFound,
	vector<int>::const_iterator endIterator, int element);

int main() {
	//Using 'find' method of Generic algorithms
	vector<int> numbers = { 0,1,2,3,4,5,6,7,8,9 };
	int numberToFind = 4;

	//find(startIerator, endIterator, valueToBeSearched)
	//If found    --> returns iterator to the first matched element
	auto iteratorToTheNumberFound = find(numbers.cbegin(), numbers.cend(), numberToFind);
	printResults(iteratorToTheNumberFound, numbers.cend(), numberToFind);

	numberToFind = 10;
	//If NotFound --> returns the end iterator supplied to the 'find' method
	iteratorToTheNumberFound = find(numbers.cbegin(), numbers.cend(), numberToFind);
	printResults(iteratorToTheNumberFound, numbers.cend(), numberToFind);

	return 0;
}

void printResults(vector<int>::const_iterator iteratorToTheNumberFound,
	vector<int>::const_iterator endIterator, int element) {

	if (iteratorToTheNumberFound == endIterator) {
		cout << "Element " << element << " is not found in the list: " << endl;
	}
	else {
		cout << "Element " << element << "found: " << *iteratorToTheNumberFound << endl;
	}
}



