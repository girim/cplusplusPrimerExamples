#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>


using namespace std;

int main() {
	//Using 'count' method of alorithms
	vector<int> oddNumbers = { 1,1,1,1,3,5,5,7,9,9,9 };

	auto numberOfOnesCount = count(oddNumbers.cbegin(), oddNumbers.cend(), 1);
	auto numberOfNinesCount = count(oddNumbers.cbegin(), oddNumbers.cend(), 9);
	auto numberOfThreesCount = count(oddNumbers.cbegin(), oddNumbers.cend(), 3);
	auto numberOfFiveCount = count(oddNumbers.cbegin(), oddNumbers.cend(), 5);

	cout << "Number of one's : " << numberOfOnesCount << endl;
	cout << "Number of Nine's : " << numberOfNinesCount << endl;
	cout << "Number of Three's : " << numberOfThreesCount << endl;
	cout << "Number of Five's : " << numberOfFiveCount << endl;

	list<string> sequence = { "aa","bb","cc","dd","dd","ee" };
	auto numberOfdds = count(sequence.cbegin(), sequence.cend(), "dd");

	cout << "Number of dd's : " << numberOfdds << endl;

	return 0;
}


