//
//  KnnString.cpp
//  ㄹㅇㅇ
//
//  Created by Andoni on 12/01/2024.
//

#include "KnnString.hpp"

KNNString::KNNString(int k) : KNN<std::vector<std::string>>(k) {}

double KNNString::similarityMeasure(const vector<std::string>& a,const vector<string>& b) const {
    // Implementation of Levenshtein Edit Distance
    // Iterative approach
    size_t m = a.size();
    size_t n = b.size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (size_t i = 0; i <= m; ++i) {
        for (size_t j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else {
                dp[i][j] = std::min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])});
            }
        }
    }

    return static_cast<double>(dp[m][n]);
}

// Explicit instantiation for the specific type
template class KNN<std::vector<std::string>>;
