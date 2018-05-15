#include <map>
#include <functional>
#include "../printAssociativeContainers.hpp"
#include "../Cone.hpp"

int main()
{
    /* 1. empty constructor */
    std::map<int, int> emptyMap;
    printAssociativeContainer(emptyMap, "emptyMap");

    /* 2. initializer_list */
    std::map<int, std::string> teamRankings = { {4, "RR"},
                                                {1, "SRH"}, 
                                                {2, "CSK"}, 
                                                {3, "MI"}};

    printAssociativeContainer(teamRankings, "teamRaknings");

    /* 3. Range */
    std::map<int, std::string, std::greater<int>> copyOfTeamRankings(++teamRankings.begin(), teamRankings.end(),  std::greater<int>());
    printAssociativeContainer(copyOfTeamRankings, "copyOfTeamRankings");

    /* 4. copy_constructor */
    std::map<int, std::string> teams(teamRankings);
    printAssociativeContainer(teams, "teams");

    /* 5. move_constructor */
    std::map<int, std::string> finalTeams(std::move(teams));
    printAssociativeContainer(finalTeams, "finalTeams");
    printAssociativeContainer(teams, "teams");

    Cone cone_1{2, 2, 2};
    Cone cone_2{};
    Cone cone_3{5, 5, 5};
    Cone cone_4{4, 4, 4};
    std::map<Cone, std::string> cones;
    cones.insert({cone_1, "cone_1"});
    cones.insert({cone_2, "cone_2"});
    cones.insert({cone_3, "cone_3"});
    cones.insert({cone_4, "cone_4"});

    printAssociativeContainer(cones, "cones");

    return 0;
}
