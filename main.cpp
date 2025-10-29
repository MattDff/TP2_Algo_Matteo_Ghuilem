//
// Created by mdoffe on 22/10/2025.
//

#include <iostream>
#include <ostream>
#include <vector>

#include "ex1.h"
#include "ex2.h"

int main() {
    // Test de l'exercice 1
    std::vector<int> V1 = {1, 2, 3, 8, 9, 4, 5, 6, 20, 9, 10};
    ex1 *test1 = new ex1(V1);
    std::vector<int> sol = test1->FindLongest();
    std::cout << "Taille de la séquence : " << sol.size() << std::endl;
    for (int i = 0; i < sol.size(); i++)
    {
        std::cout << sol[i] << std::endl;
    }

    // Test de l'exercice 2
    std::vector<int> V2 = {1, 6, 11, 5, 10, 15, 20, 2, 4, 9};
    int k2 = 7;
    ex2 *test2 = new ex2(V2, k2);
    std::vector<int> sol2 = test2->FindLongestDivisible();
    std::cout << "Taille de la séquence : " << sol2.size() << std::endl;
    for (int i = 0; i < sol2.size(); i++) {
        std::cout << sol2[i] << std::endl;
    }

    //2ème Test de l'exercice 2
    std::vector<int> V2_2 = {1, 6, 11, 5, 10, 15, 20, 2, 4, 13};
    int k2_2 = 7;
    ex2 *test2_2 = new ex2(V2_2, k2_2);
    std::vector<int> sol2_2 = test2_2->FindLongestDivisible();
    std::cout << "Taille de la séquence : " << sol2_2.size() << std::endl;
    for (int i = 0; i < sol2_2.size(); i++) {
        std::cout << sol2_2[i] << std::endl;
    }

    return 0;
}