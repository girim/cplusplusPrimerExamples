#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

int main() {
	//Copying algorithms
	//replace(startIterator, endIterator, valueToBeReplaced, newValue)
	//replace_copy(startIterator,endIterator, destinationIterator, valueToBeReplaced, newValue)
	vector<string> euroCountries = { "Poland","Czech","Germany","France","Finland","France","Sweeden"};

	//replace()
	cout << "Before replace: " << endl;
	for (auto country : euroCountries) {
		cout << country << " " ;
	}

	cout <<endl << "After replace: " << endl;
	//used string("France") becuase arguement should be of type const char*
	replace(euroCountries.begin(), euroCountries.end(), string("France"), string("Belgium"));
	for (auto country : euroCountries) {
		cout << country << " ";
	}

	//replace_copy()
	list<int> numbers = { 1,2,1,4,1,6,1,8,1 };
	list<int> evenNumbers;
	//back_inserter is used to creat an destination iterator
	replace_copy(numbers.begin(), numbers.end(), back_inserter(evenNumbers), 1, 0);

	for (auto evenNumber : evenNumbers) {
		cout << evenNumber << endl;
	}

	return 0;
}
