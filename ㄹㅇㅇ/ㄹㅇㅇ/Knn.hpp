// Knn.hpp

#ifndef Knn_hpp
#define Knn_hpp

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <typename T>
class KNN {
public:
    KNN(int k);
    int getK() const;
    vector<int> findNearestNeighbours(const vector<T>& trainData, const T& target);
    virtual double similarityMeasure(const T& a, const T& b) const = 0;

private:
    int k;
};


template <typename T>
KNN<T>::KNN(int k) : k(k) {}

template <typename T>
int KNN<T>::getK() const {
    return k;
}

template <typename T>
vector<int> KNN<T>::findNearestNeighbours(const vector<T>& trainData, const T& target) {
    // Calculate similarity for each item in trainData
    vector<pair<double, int>> similarities;  // Pair of similarity and index

    for (size_t i = 0; i < trainData.size(); ++i) {
        double similarity = similarityMeasure(trainData[i], target);
        similarities.push_back({similarity, static_cast<int>(i)});
    }

    // Sort by similarity in descending order
    sort(similarities.begin(), similarities.end(), greater<pair<double, int>>());

    // Select the top k indices
    vector<int> neighbors;
    for (int i = 0; i < k && i < similarities.size(); ++i) {
        neighbors.push_back(similarities[i].second);
    }

    return neighbors;
}

#endif /* Knn_hpp */
