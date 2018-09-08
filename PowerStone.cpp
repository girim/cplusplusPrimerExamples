#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <math.h>

#define MAX_SIZE 500
int hardnessValues[MAX_SIZE];
std::vector<std::array<int, 3>> stoneCombs = \
{{3,3,3}, {3,2,3}, {3,3,2}, {2,3,3}, {3,2,2},
 {2,2,3}, {2,3,2}, {3,3,1}, {2,2,2},
 {2,3,1}, {3,2,1}, {1,2,3}, {2,2,1}, {1,2,2},
 {1,3,3}, {1,3,2}, {1,3,1}, {1,2,1},
 {3,1,3}, {3,1,2}, {3,1,1}, {2,1,3},
 {2,1,2}, {2,1,1}, {1,1,3}, {1,1,2}, {1,1,1}};

long long int findPower(int first, int second, int third)
{
    return pow(second, pow(first, third));
}

bool findSequence(std::vector<std::array<int, 3>>::iterator &iterToSubSeq, \
                std::list<int>::iterator &ptr, std::list<int> &stoneline)
{
    bool found = false;
    int counter = 0;
    auto arrayIter = iterToSubSeq->begin();
    while(arrayIter != iterToSubSeq->end())
    {
        if( ptr == stoneline.end())
        {
            counter = 0;
            break;
        }
        if(*arrayIter != *ptr && counter == 0)
        {
            ++ptr;
        }
        else if(*arrayIter == *ptr)
        {
            ++counter;
            ++ptr;
            ++arrayIter;
        }
        else if( (*arrayIter != *ptr) && counter > 0)
        {
            if(counter == 3)
            {
                break;
            }
            counter = 0;
            arrayIter = iterToSubSeq->begin();
        }

        if(counter == 3)
        {
            found =  true;
            break;
        }
    }

    return found;
}

int solve(int numberOfStones, long long strengthOfLine)
{
    std::list<int> stoneline(std::begin(hardnessValues), std::begin(hardnessValues)+numberOfStones);

    std::list<int>::iterator ptr;
    int powerSpentInBreakingStone = 0;
    long long decreasedStrengthOfLine = 0;

    while(stoneline.size() > 2)
    {
        ptr =  stoneline.begin();
        auto iter  = stoneCombs.begin();
        bool hit = false;

        while(iter != stoneCombs.end())
        {
            ptr =  stoneline.begin();
            bool res = findSequence(iter, ptr, stoneline);

            if(res)
            {
                auto thirdNumber = --ptr;
                auto secondNumber = --ptr;
                auto firstNumber = --ptr;
                powerSpentInBreakingStone = powerSpentInBreakingStone + *(secondNumber);
                decreasedStrengthOfLine = decreasedStrengthOfLine + findPower(*firstNumber, *secondNumber, *thirdNumber);
                stoneline.erase(secondNumber);
            }else{
                hit = false;
                /* Remove stones one by one and check for max power */
                auto copyOfStoneline = stoneline;
                auto iterToBeRemoved  = ++stoneline.begin();
                int size =  (copyOfStoneline.size() - 2);
                int counter = 0;
                int offset = 1;

                auto firstCpy = iterToBeRemoved;
                auto cpyOfIter  = iterToBeRemoved;
                auto secondIter = iterToBeRemoved;
                auto firstIter  = --firstCpy;
                auto thirdIter = ++cpyOfIter;
                
                stoneline.erase(iterToBeRemoved);

                long long decStrength = findPower(*firstIter, *secondIter, *thirdIter);
                int pwrSpent = *secondIter;

                while(counter < size)
                {
                    ptr = stoneline.begin();

                    auto result = findSequence(iter, ptr, stoneline);

                    if(result)
                    {
                        auto thirdNumber = --ptr;
                        auto secondNumber = --ptr;
                        auto firstNumber = --ptr;
                        powerSpentInBreakingStone = powerSpentInBreakingStone + *(secondNumber);
                        decreasedStrengthOfLine = decreasedStrengthOfLine + findPower(*firstNumber, *secondNumber, *thirdNumber);
                        powerSpentInBreakingStone += pwrSpent;
                        decreasedStrengthOfLine += decStrength;

                        stoneline.erase(secondNumber);
                        copyOfStoneline = stoneline;
                        hit = true;
                        break;
                    }else{
                        stoneline = copyOfStoneline;
                        ++counter;
                        auto nextIter = stoneline.begin();
                        int pos = 0;
                        while(pos < (counter + offset))
                        {
                            ++nextIter;
                            ++pos;
                        }

                        auto cpy  = nextIter;
                        auto copyOfNextIter = nextIter;
                        auto secondIt = nextIter;
                        auto firstIt  = --cpy;
                        auto thirdIt = ++copyOfNextIter;
                        pwrSpent = *secondIt;
                        decStrength = findPower(*firstIt, *secondIt, *thirdIt);

                        stoneline.erase(nextIter);
                    }
                }
                stoneline = copyOfStoneline;

                if(!hit)
                {
                   ++iter;
                }else{
                    iter = stoneCombs.begin();
                }
            }
        }
    }

    int minimumPoweReq = (strengthOfLine - decreasedStrengthOfLine) +  powerSpentInBreakingStone;

    return minimumPoweReq;
}

int main()
{
    int numberOfStones  = 0;
    long long strengthOfLine = 0;

    scanf("%d %lld", &numberOfStones, &strengthOfLine);
    for(int index = 0; index < numberOfStones; index++)
    {
        scanf("%d", &hardnessValues[index]);
    }
    int ans = solve(numberOfStones, strengthOfLine);
    std::cout << ans << EOL;
   
    return 0;
}