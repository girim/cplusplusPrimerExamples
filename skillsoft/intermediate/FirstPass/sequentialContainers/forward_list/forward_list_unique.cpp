#include <forward_list>
#include <cmath>
#include "../printContainerContents.hpp"
#include "../Plane.hpp"

bool hasSameIntegralPart(const double& prev, const double& cur)
{
    return (static_cast<int>(prev) == static_cast<int>(cur));
}

class isNearClass
{
    public:
        bool operator()(const double& prev, const double& cur)
        {
            return (std::fabs(prev - cur) < 5.0);
        }
};

int main()
{
    std::forward_list<double> fractions{15.2, 73.0, 3.14, 15.85, 69.5,
                                       73.0, 3.99, 15.2, 69.2,  18.5};
    
    printContainerContents(fractions, "fractions_1");

    fractions.sort();
    printContainerContents(fractions, "fractions_2");

    /* Unique without binary predicate */
    fractions.unique();
    printContainerContents(fractions, "fractions_3");

    /* Unique with binary predicate */
    fractions.unique(hasSameIntegralPart);
    printContainerContents(fractions, "fractions_3");

    fractions.unique(isNearClass());
    printContainerContents(fractions, "fractions_4");

    return 0;
}