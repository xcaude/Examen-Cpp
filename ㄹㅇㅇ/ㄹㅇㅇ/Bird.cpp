//
//  Bird.cpp
//  ㄹㅇㅇ
//
//  Created by Andoni on 12/01/2024.
//

#include "Bird.hpp"


Bird::Bird()
        : Animal(), wingspan(0.5) {
}

Bird::Bird(string name, string color, double wingspan, string diet, string habitat, string sounds, bool isPet, int age, double weight, double height)
        : Animal( name, color, diet, habitat, sounds, isPet, age, weight, height), wingspan(wingspan) {

}

Bird::Bird(const Bird &bird)
        : Animal(bird.getName(), bird.getColor(), bird.getDiet(), bird.getHabitat(), bird.getSounds(), bird.getIsPet(), bird.getAge(),
                 bird.getWeight(), bird.getHeight()), wingspan(bird.wingspan) {
}

void Bird::setWingspan(double newWingspan) {
    wingspan = newWingspan;
}

double Bird::getWingspan() const {
    return wingspan;
}

void Bird::printInfo() {
    cout << "Animal of type Bird:" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Color: " << getColor() << endl;
    cout << "Wingspan: " << wingspan << " meters" << endl;
    cout << "Diet: " << getDiet() << endl;
    cout << "Habitat: " << getHabitat() << endl;
    cout << "Sounds: " << getSounds() << endl;
    cout << "Is Pet: " << (getIsPet() ? "" : "not ") << "a pet" << endl;
    cout << "Age: " << getAge() << " years" << endl;
    cout << "Weight: " << getWeight() << " kg" << endl;
    cout << "Height: " << getHeight() << " meters" << endl;
}

