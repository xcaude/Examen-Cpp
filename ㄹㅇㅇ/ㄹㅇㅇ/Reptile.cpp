//
//  Reptile.cpp
//  ㄹㅇㅇ
//
//  Created by Andoni on 12/01/2024.
//

#include "Reptile.hpp"


Reptile::Reptile()
        : Animal(), scalePattern("") {
}

Reptile::Reptile(string name, string color, string scalePattern, string diet, string habitat, string sounds, bool isPet, int age, double weight, double height)
        : Animal( name, color, diet, habitat, sounds, isPet, age, weight, height), scalePattern(scalePattern){
}

Reptile::Reptile(const Reptile &reptile)
        : Animal(reptile.getName(), reptile.getColor(), reptile.getDiet(), reptile.getHabitat(), reptile.getSounds(), reptile.getIsPet(), reptile.getAge(),
                 reptile.getWeight(), reptile.getHeight()), scalePattern(reptile.scalePattern) {
}

void Reptile::setScalePattern(const string &newScalePattern) {
    scalePattern = newScalePattern;
}

string Reptile::getScalePattern() const {
    return scalePattern;
}

void Reptile::printInfo() {
    cout << "Animal of type Reptile:" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Color: " << getColor() << endl;
    cout << "Scale Pattern: " << scalePattern << endl;
    cout << "Diet: " << getDiet() << endl;
    cout << "Habitat: " << getHabitat() << endl;
    cout << "Sounds: " << getSounds() << endl;
    cout << "Is Pet: " << (getIsPet() ? "" : "not ") << "a pet" << endl;
    cout << "Age: " << getAge() << " years" << endl;
    cout << "Weight: " << getWeight() << " kg" << endl;
    cout << "Height: " << getHeight() << " meters" << endl;

}
