//
//  KnnDouble.cpp
//  ㄹㅇㅇ
//
//  Created by Andoni on 12/01/2024.
//

#include "KnnDouble.hpp"

KNNDouble::KNNDouble(int k) : KNN<std::pair<double, double>>(k) {}

double KNNDouble::similarityMeasure(const pair<double, double>& a, const pair<double, double>& b) const {
    double distance = std::sqrt(std::pow(a.first - b.first, 2) + std::pow(a.second - b.second, 2));
    return distance;
}

template class KNN<std::pair<double, double>>;
