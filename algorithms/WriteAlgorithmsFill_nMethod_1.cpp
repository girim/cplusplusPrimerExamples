#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	//Algorithms that Write Container Elements
	//fill(startIterator, endIterator,value)
	vector<int> numbers = { 0,1,2,3,4,5,6,7,8,9 };
	list<string> phones = { "Apple","Samsung","Blackberry" };

	fill_n(numbers.begin(), numbers.size(), 0);

	for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
		cout << *iter << endl;
	}

	return 0;
}



