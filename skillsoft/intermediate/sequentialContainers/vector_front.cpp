#include <vector>
#include "printVectorContents.hpp"

int main()
{
    /* std::vector::front
        Returns a reference to the first element in the vector.
        --> reference front();
        --> const_reference front() const;
     */

    std::vector<std::string> colors {"red", "green", "blue"};
    printVectorContents(colors, "colors");

    std::cout << "Color at the front is: " << colors.front() << std::endl;
    colors.front() = "Yellow";

    printVectorContents(colors, "colorsAfter");

    const std::vector<std::string> webTechs{"css", "html", "js"};
    std::cout << "WebTechs front is : " << webTechs.front() << std::endl;

    //webTechs.front() = "html5"; //Returs reference to the const so cannot assign 

    return 0;
}