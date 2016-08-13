#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	//Algorithm that operates on two sequences
	//equal(startIterOfFirstSequence, endIteratorOfSecondSequence,startIterOfSecondSequence)
	//return true if ==, false if !=
	//algorithm assumes second sequence is atleast as big as the first sequence
	vector<int> numbers = { 2,4,6,8,10 };
	vector<int> evenNumbers = { 2,4,6,8,10 };

	auto isEqual = equal(numbers.cbegin(), numbers.cend(), evenNumbers.cbegin());
	cout << "Is equal? " << isEqual << endl;

	vector<string> languages = { "C","C++","Java","JavaScript" };
	vector<string> otherLanguges = { "Python","Ruby" };

	isEqual = equal(languages.cbegin(), languages.cend(), otherLanguges.cbegin());
	cout << "Is equal? " << isEqual << endl;

	//If second sequence length is more still it returns true
	vector<int> integers = { 1,3,5,7,9 };
	vector<int> oddNumbers = { 1,3,5,7,9,10 };

	isEqual = equal(integers.cbegin(), integers.cend(), oddNumbers.cbegin());
	cout << "Is equal? " << isEqual << endl;

	vector<double > rates = { 1.1, 2.2,3.3,4.4 };
	vector<double>  lessRates = { 1.1, 2.2, 3.3 };
	//Call to equal crashes as second sequence lenth is less than first sequence
	//isEqual = equal(rates.cbegin(), rates.cend(), lessRates.cbegin());
	//cout << "Is equal? " << isEqual << endl;

	//We can compare two different types of Containers having compatible types of elements
	vector<string> authors = { "Lipmen","Lajoie","Moo" };
	list<const char*> cplusplusPrimerAuthors = { "Lipmen","Lajioe","Moo" };

	isEqual = equal(authors.cbegin(), authors.cend(), cplusplusPrimerAuthors.cbegin());
	cout << "Is Equal? " << isEqual << endl;

	return 0;
}


