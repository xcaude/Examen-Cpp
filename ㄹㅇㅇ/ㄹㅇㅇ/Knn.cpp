//
//  Knn.cpp
//  ㄹㅇㅇ
//
//  Created by Andoni on 12/01/2024.
//

#include "Knn.hpp"

#include <algorithm>

template <typename T>
KNN<T>::KNN(int k) : k(k) {}

template <typename T>
int KNN<T>::getK() const {
    return k;
}

template <typename T>
vector<int> KNN<T>::findNearestNeighbours(std::vector<T>& trainData, T& target) {
    return {3};
}

