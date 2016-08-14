#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

int main() {
	//Using back_inserter to get the destination iterator
	list<int> listOfNumbers = { 10,20,30,40,50 };
	//back_inserter takes reference to the Container and returns an iterator 
	//that we can use it for adding the new element to the container
	auto iter = back_inserter(listOfNumbers);
	*iter = 60;                                  //insert element at the back

	for (auto iter = listOfNumbers.begin(); iter != listOfNumbers.end(); iter++) {
		cout << *iter << endl;
	}

	vector<string> books;
	//Back_inserter is used to create a destination iterator for fill_n() & can write elements
	// to empty container
	fill_n(back_inserter(books), 10, "c++");

	for (auto book : books) {
		cout << book << endl;
	}

	return 0;
}
