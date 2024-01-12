//
//  Reptile.hpp
//  ㄹㅇㅇ
//
//  Created by Andoni on 12/01/2024.
//

#ifndef Reptile_hpp
#define Reptile_hpp

#include "Animal.hpp"

class Reptile : public Animal {
public:
    Reptile();
    Reptile(string name, string color, string scalePattern, string diet, string habitat, string sounds, bool isPet, int age, double weight, double height);
    Reptile(const Reptile &reptile);

    void setScalePattern(const string &newScalePattern);
    string getScalePattern() const;

    void printInfo() override;

private:
    string scalePattern;
};

#endif /* Reptile_hpp */
