#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main()
{
    std::vector<int> sequence {6, 2, 0, 1, 1, 3, 9, 8, 7, 0, 1, 1, 5};
    std::vector<int> subSequence {0, 1, 1};

    //Without predicate
    auto iter_1 = std::find_end(sequence.begin(), sequence.end(), subSequence.begin(), subSequence.end());
    std::cout << "position of the found subSequence is: " << iter_1 - sequence.begin() << std::endl;
    std::cout << "Element in the sequence are : " << *iter_1 << " " << *(iter_1 + 1) <<  " "  << *(iter_1 + 2) << std::endl;

    //With predicate
    auto iter_2 = std::find_end(sequence.begin(), sequence.end(), subSequence.begin(), subSequence.end(), \
                                    [](const int& seqElement, const int& subSeqElement){
                                            std::cout << "seqElement: " << seqElement << std::endl;
                                            std::cout << "subSeqElement: " << subSeqElement << std::endl;
                                            return (seqElement == subSeqElement);
                                    });
    std::cout << "position of the found subSequence with predicate is: " << iter_2 - sequence.begin() << std::endl;
                        
    return 0;
}