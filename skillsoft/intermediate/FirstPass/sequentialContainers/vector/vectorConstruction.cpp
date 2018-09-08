#include <vector>
#include <utility>
#include "Plane.hpp"

template<typename T>
void printElements(const T& vec, std::string name)
{
    for(const auto& element : vec)
        std::cout << "element of " << name << " is: " << element << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Plane& plane)
{
    os << "{length: " << plane.getLength() << " ,width: "  \
        << plane.getWidth() << ", area: " << plane.getAreaOfPlane() <<  "}";
}

int main()
{
    int numbers[] = {1,2,3,4};
    //Different ways of constructing a vector
    //1.Default constructor
    std::vector<int> first;

    //2.Fill constructor
    std::vector<float> second(3);
    std::vector<double> third(4, 1.1);

    //3.range constructor
    std::vector<double> fourth(third.begin(), third.end());
    std::cout <<"size of numbers: " << sizeof(numbers) << " " << sizeof(int)<< std::endl;
    std::vector<int> eighth(numbers, numbers+(sizeof(numbers)/sizeof(int)));

    //4.intializer list
    std::vector<char> fifth{'a','b','c','d'};

    //5.copy constructor
    std::vector<float> sixth(second);

    //6.move constructor
    std::vector<char> charVect{'1','2'};
    std::vector<char> seventh(std::move(charVect));

    std::cout << "size of vector charVect is: " << charVect.size() << std::endl;

    printElements(first, "first");
    printElements(second, "second");
    printElements(third, "third");
    printElements(fourth, "fourth");
    printElements(fifth, "fifth");
    printElements(sixth, "sixth");
    printElements(seventh, "seventh");
    printElements(eighth, "eigth");

    Plane p1{4,8};
    std::cout << p1 << std::endl;

    std::vector<Plane> planeList_0{};  //Using default constructor
    printElements(planeList_0, "PlaneList_0"); //empty list

    std::vector<Plane> planeList_1(2);
    printElements(planeList_1, "PlaneList_1");

    std::vector<Plane> planeList_2(2, p1); //p1 is copied twice here
    printElements(planeList_2, "PlaneList_2");

    std::vector<Plane> planeList_3(planeList_2); //Using copy constructor
    printElements(planeList_3, "PlaneList_3");

    std::vector<Plane> planeList_4(std::move(planeList_3)); //Using move constructor
    printElements(planeList_4, "PlaneList_4");
    printElements(planeList_3, "PlaneList_3");

    Plane pl1{1,2};
    Plane pl2{2,3};
    Plane pl3{3,4};
    std::vector<Plane> planeList_5{std::move(pl1), std::move(pl2), std::move(pl3)};
    std::cout << pl1 << std::endl;

    planeList_2 = planeList_4;

    return 0;
}