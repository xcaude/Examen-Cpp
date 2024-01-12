//
//  KnnDouble.hpp
//  ㄹㅇㅇ
//
//  Created by Andoni on 12/01/2024.
//

#ifndef KnnDouble_hpp
#define KnnDouble_hpp

#include "Knn.hpp"
using namespace std;

class KNNDouble : public KNN<pair<double, double>> {
public:
    KNNDouble(int k);
    double similarityMeasure(const pair<double, double>& a,const pair<double, double>& b) const override;
};
#endif /* KnnDouble_hpp */
