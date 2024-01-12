//
//  Bird.hpp
//  ㄹㅇㅇ
//
//  Created by Andoni on 12/01/2024.
//

#ifndef Bird_hpp
#define Bird_hpp

#include <stdio.h>
#include "Animal.hpp"

class Bird : public Animal{
public :

    Bird();
    Bird(string _name, string _color, double _wingspan, string _diet, string _habitat, string _sounds, bool _isPet, int _age, double _weight, double _height);
    Bird(Bird const &bird);

    void printInfo() override;
    void setWingspan(double newWingspan);
    double getWingspan() const;

protected:
    double wingspan;

};

#endif /* Bird_hpp */
