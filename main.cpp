//
// Created by mdoffe on 22/10/2025.
//

#include <iostream>
#include <ostream>
#include <vector>

#include "ex1.h"

int main() {
    // Test de l'exercice 1
    std::vector<int> V = {1, 2, 3, 8, 9, 4, 5, 6, 20, 9, 10};
    ex1 *test = new ex1(V);
    std::vector<int> sol = test->FindLongest();
    std::cout << "Taille de la séquence : " << sol.size() << std::endl;
    for (int i = 0; i < sol.size(); i++) {
        std::cout << sol[i] << std::endl;
    }
    return 0;
}