#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	//Algorithms that write Container elements
	// fill(startIterator, endIterator, value)
	// fill_n(destinationIterator, numberOfElements, value)

	vector<int> integers = { 0,1,2,3,4,5,6,7,8,9 };
	fill(integers.begin(), integers.end(), 100);

	for (auto iter = integers.begin(); iter != integers.end(); iter++) {
		cout << *iter << endl;
	}

	//You can specify the destination iterator
	fill_n(integers.begin(), integers.size(), 400);

	for (auto iter = integers.begin(); iter != integers.end(); iter++) {
		cout << *iter << endl;
	}

	//You can specify the destination iterator
	fill_n(integers.begin() + 5, 4, 1);

	for (auto iter = integers.begin(); iter != integers.end(); iter++) {
		cout << *iter << endl;
	}
	return 0;
}



