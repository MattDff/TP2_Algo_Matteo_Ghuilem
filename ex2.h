//
// Created by mdoffe on 22/10/2025.
//

#ifndef TP2_ALGO_MATTEO_GHUILEM_EX2_H
#define TP2_ALGO_MATTEO_GHUILEM_EX2_H
#include <vector>

class ex2 {
private:
    std::vector<int> V;
    int n;
    int k;
public:
    ex2(std::vector<int> arr, int k);
    std::vector<int> FindLongestDivisible();
    std::vector<int> reconstructSolution(int best_end, int best_remainder, const std::vector<std::vector<int>>& dp,
                                         const std::vector<std::vector<int>>& prev);
};


#endif //TP2_ALGO_MATTEO_GHUILEM_EX2_H