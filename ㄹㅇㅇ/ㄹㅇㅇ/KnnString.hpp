//
//  KnnString.hpp
//  ㄹㅇㅇ
//
//  Created by Andoni on 12/01/2024.
//

#ifndef KnnString_hpp
#define KnnString_hpp

#include "Knn.hpp"

#include <vector>


class KNNString : public KNN<vector<string>> {
public:
    KNNString(int k);
    double similarityMeasure(const vector<string>& a, const vector<string>& b) const override;
};

#endif /* KnnString_hpp */
