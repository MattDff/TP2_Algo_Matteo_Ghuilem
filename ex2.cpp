//
// Created by mdoffe on 22/10/2025.
//

#include "ex2.h"

#include <algorithm>


ex2::ex2(std::vector<int> arr, int k) : V(arr), k(k) {
    n = arr.size();
}


std::vector<int> ex2::FindLongestDivisible() {
    std::vector<std::vector<int>> dp(n, std::vector<int>(k, 0));
    std::vector<std::vector<int>> prev(n, std::vector<int>(k, -1));

    int max_len = 0;
    int best_end = -1;
    int best_remainder = -1;

    // Initialisation : chaque élément seul forme une sous-séquence de longueur 1
    for (int i = 0; i < n; i++) {
        int remainder = V[i] % k;
        dp[i][remainder] = 1;
        prev[i][remainder] = -1;

        if (remainder == 0 && 1 > max_len) {
            max_len = 1;
            best_end = i;
            best_remainder = 0;
        }
    }

    // Remplissage du tableau DP
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int current_remainder = V[i] % k;

            for (int r = 0; r < k; r++) {
                if (dp[j][r] > 0) {  // Si l'état est valide
                    int new_remainder = (r + current_remainder) % k;
                    int new_length = dp[j][r] + 1;

                    if (new_length > dp[i][new_remainder]) {
                        dp[i][new_remainder] = new_length;
                        prev[i][new_remainder] = j;

                        if (new_remainder == 0 && new_length > max_len) {
                            max_len = new_length;
                            best_end = i;
                            best_remainder = 0;
                        }
                    }
                }
            }
        }
    }


    if (max_len == 0) {
        return std::vector<int>();
    }

    return ex2::reconstructSolution(best_end, best_remainder, dp, prev);
}

std::vector<int> ex2::reconstructSolution(int best_end, int best_remainder,
                                       const std::vector<std::vector<int>>& dp,
                                       const std::vector<std::vector<int>>& prev) {
    std::vector<int> result;

    if (best_end == -1) {
        return result;
    }

    int current_i = best_end;
    int current_r = best_remainder;

    while (current_i != -1) {
        // Ajouter l'élément actuel
        result.push_back(V[current_i]);

        if (dp[current_i][current_r] == 1) {
            // Element seul
            break;
        }

        // Trouver le précédent
        bool found = false;
        int prev_i = -1;
        int prev_r = -1;

        // Rechercher parmi tous les états précédents possibles
        for (int j = 0; j < current_i; j++) {
            int candidate_r = (current_r - (V[current_i] % k) + k) % k;
            if (dp[j][candidate_r] + 1 == dp[current_i][current_r]) {
                prev_i = j;
                prev_r = candidate_r;
                found = true;
                break;
            }
        }

        if (!found) {
            break;
        }

        current_i = prev_i;
        current_r = prev_r;
    }

    // Inverser pour obtenir l'ordre correct d'après l'exemple donné dans l'énoncé (optionnel à notre avis mais peu s'avérer utile dans certains cas)
    std::reverse(result.begin(), result.end());
    return result;
}