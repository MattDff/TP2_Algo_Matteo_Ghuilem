//
// Created by mdoffe on 22/10/2025.
//

#include "ex1.h"

#include <algorithm>

ex1::ex1(std::vector<int> arr)
    : V(arr) {
    n = arr.size();
}

std::vector<int> ex1::FindLongest() {
    std::vector<int> dp(n, 1);       // longueur de la plus longue sequence se terminant à l'index i
    std::vector<int> prev(n, -1);    // indice du précédent élément dans la sequence

    int max_len = 1;
    int best_end = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (V[j] < V[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > max_len) {
            max_len = dp[i];
            best_end = i;
        }
    }

    // reconstruction de la sous-séquence
    std::vector<int> lis;
    for (int i = best_end; i != -1; i = prev[i])
        lis.push_back(V[i]);

    reverse(lis.begin(), lis.end());

    return lis;
}