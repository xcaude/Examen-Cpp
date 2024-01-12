//
//  Mammal.cpp
//  ㄹㅇㅇ
//
//  Created by Andoni on 12/01/2024.
//

#include "Mammal.hpp"

Mammal::Mammal():
Animal(), furColor("")
{
}

Mammal::Mammal(string _name, string _color, string _furColor, string _diet, string _habitat, string _sounds, bool _isPet, int _age, double _weight, double _height)
        : Animal( _name, _color, _diet, _habitat, _sounds, _isPet, _age, _weight, _height), furColor(_furColor)
        {

}

Mammal::Mammal(const Mammal &mammal)
        : Animal( mammal.name, mammal.color, mammal.diet, mammal.habitat, mammal.sounds, mammal.isPet, mammal.age,
          mammal.weight, mammal.height), furColor(mammal.furColor)
          {
}


void Mammal::setFurColor(string newFurColor) {
    furColor=newFurColor;
}

string Mammal::getFurColor() const {
    return furColor;
}

void Mammal::printInfo() {
    cout << "Animal of type Reptile:" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Color: " << getColor() << endl;
    cout << "Fur Color: " << furColor << endl;
    cout << "Diet: " << getDiet() << endl;
    cout << "Habitat: " << getHabitat() << endl;
    cout << "Sounds: " << getSounds() << endl;
    cout << "Is Pet: " << (getIsPet() ? "" : "not ") << "a pet" << endl;
    cout << "Age: " << getAge() << " years" << endl;
    cout << "Weight: " << getWeight() << " kg" << endl;
    cout << "Height: " << getHeight() << " meters" << endl;
}
