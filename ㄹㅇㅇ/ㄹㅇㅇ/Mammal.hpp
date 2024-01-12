//
//  Mammal.hpp
//  ㄹㅇㅇ
//
//  Created by Andoni on 12/01/2024.
//

#ifndef Mammal_hpp
#define Mammal_hpp

#include "Animal.hpp"

class Mammal : public Animal{

public :

    Mammal();
    Mammal(string _name, string _color, string _furColor, string _diet, string _habitat, string _sounds, bool _isPet, int _age, double _weight, double _height);
    Mammal(Mammal const &mammal);

    void printInfo() override;
    void setFurColor(string newFurColor);
    string getFurColor() const;

protected:
    string furColor;
};

#endif /* Mammal_hpp */
