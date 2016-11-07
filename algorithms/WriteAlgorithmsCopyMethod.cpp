#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

int main() {
	//Copy Assignments
	//copy(startIterator, endIterator, destinationIterator)
	int numbers[] = { 1,2,3,4,5,6,7,8,9 };
	int copyOfNumbers[sizeof(numbers) / sizeof(int)];

	//copy elements from 'numbers' to 'copyOfNumbers'
	copy(begin(numbers), end(numbers), copyOfNumbers);

	for (auto number : copyOfNumbers) {
		cout << number << endl;
	}

	list<string> states = { "KAR","AP","TN","KER" };
	list<string> copyOfStates;

	//back_inserter is used to get the destination iterator for empty list
	copy(states.begin(), states.end(), back_inserter(copyOfStates));

	for (auto state : states) {
		cout << state << endl;
	}

	return 0;
}

