#include <vector>
#include "printVectorContents.hpp"
#include "Plane.hpp"

std::ostream& operator<<(std::ostream& os, const Plane& plane)
{
    os << "{ length: " << plane.getLength() <<  " width: " << plane.getWidth() \
        << " Area: " << plane.getAreaOfPlane() << " }";

    return os;
}

int main()
{
    std::vector<int> intergers{1000, 2000};
    printVectorContents(intergers, "integers_1");

    /* Returns iterators to the position of the first element which is inserted  */
    //1. insert(position, value)
    std::vector<int>::iterator iterToFirst = intergers.insert(intergers.begin(), 900);
    printVectorContents(intergers, "integers_2");

    //2. insert(position, begin, end)
    int numbers[] = {100, 100};
    auto iter = intergers.insert(iterToFirst, std::begin(numbers), std::end(numbers));
    printVectorContents(intergers, "integers_3");

    //3. insert(position, initializer_list)
    iter = intergers.insert(iter+2, {10,20,30});
    printVectorContents(intergers, "integers_4");
    std::cout << "Iter retured post insertion is: " << *iter << std::endl;

    //4. insert(position, n, value)
    iter = intergers.insert(intergers.begin()+3, 2, 0);
    printVectorContents(intergers, "integers_5");

    //5. insert(position, move)
    int numberSix = 6;
    intergers.insert(iter, std::move(numberSix));

    intergers.insert(intergers.end(), {1,1,1});
    printVectorContents(intergers, "integers_6");

    return 0;
}