#include <iostream>
#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

/* predefined iterator classes
1. back_insert_iterator
2. front_insert_iterator
3. insert_iterator
4. istream_iterator
5. ostream_iterator
6. move_iteraror
7. reverse_iterator
8. istreambuf_iterator
9. ostreambuf_iterator
*/
#define EOL "\n"

template<typename T>
void printContainer(const T& container)
{
    for(auto iter = container.cbegin(); iter != container.cend(); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << EOL;
}

int main(int argc, char* argv[])
{
    /* 1. back_insert_iterator  -- Need push_back method */
    std::vector<int> src = {10, 20,30,40}, dst;
    std::back_insert_iterator<std::vector<int>> backIt(dst);

    std::copy(src.begin(), src.end(), backIt);
    printContainer(dst);

    /* 2. front_insert_iterator -- Need push_front method */
    std::deque<int> srcQue = {1,2,3, 4}, dstQue;
    std::front_insert_iterator<std::deque<int>> frontIt(dstQue);

    std::copy(srcQue.begin(), srcQue.end(), frontIt);
    printContainer(dstQue);

    /* 3. insert_iterator -- Need insert method */
    std::list<std::string> srcList = {"c++", "java", "javaScript", "python"}, dstList;
    std::insert_iterator<std::list<std::string>> insertIt(dstList, dstList.begin());

    std::copy(srcList.begin(), srcList.end(), insertIt);
    printContainer(dstList);

    /* 4. istream_iterator */
    int value1, value2;
    std::cout << "please enter two numbers: "; 
    std::istream_iterator<int> endOfStream;
    std::istream_iterator<int> istreamIt(std::cin);

    if(istreamIt != endOfStream) 
        value1 = *istreamIt;

    ++istreamIt;

    if(istreamIt != endOfStream)
        value2 = *istreamIt;

    std::cout << "value1: " << value1 << " value2: " << value2 << EOL;

    /* 5. ostream_iterator */
    std::ostream_iterator<std::string> ostreamIt(std::cout, ",");
    std::copy(srcList.begin(), srcList.end(), ostreamIt);
    std::cout << EOL;

    /* 6. move_iterator  -- dereferencing will return rvalue reference*/
    std::vector<std::string> countries = {"India", "Russia", "USA", "Poland"}, destinations;
    typedef std::vector<std::string>::iterator Iter;

    std::move_iterator<Iter> beginIter(countries.begin()); 
    auto endIter = std::move_iterator<Iter>(countries.end());
    std::copy(beginIter, endIter, std::back_inserter(destinations));

    printContainer(countries);
    countries.clear();
    printContainer(destinations);

    return 0;
}



