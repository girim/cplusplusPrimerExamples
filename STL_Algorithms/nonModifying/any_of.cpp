#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include "../point.hpp"

int main(int argc, char const *argv[])
{
    std::set<std::string> languages = {"C", "C++", "Java", "JavaScript", "Python"};

    bool result = std::any_of(languages.begin(), languages.end(), [](const std::string& language){
        return (language.at(0) == 'P');
    });

    std::cout << "Any of the langauge begins with P ? " << std::boolalpha << result << "\n";

    Point pt0{}, pt1{1}, pt2{2}, pt3{3, 5};
    std::map<Point, std::string> points;
    points.emplace(pt0, "A");
    points.emplace(pt1, "B");
    points.emplace(pt2, "C");
    points.emplace(pt3, "D");

    result =  std::any_of(points.begin(), points.end(), [](const std::pair<Point, std::string>& point){
            return (point.first.getX() != point.first.getY());
    });
    std::cout << "Any point with x != y? " << std::boolalpha << result << "\n";
    
    return 0;
}

