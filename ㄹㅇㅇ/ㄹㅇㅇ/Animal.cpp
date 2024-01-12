//
//  Animal.cpp
//  ㄹㅇㅇ
//
//  Created by Andoni on 12/01/2024.
//

#include "Animal.hpp"

Animal::Animal() {
}

Animal::Animal(string _name, string _color, string _diet, string _habitat, string _sounds, bool _isPet, int _age, double _weight, double _height)
        : name(_name), color(_color), diet(_diet), habitat(_habitat), sounds(_sounds), isPet(_isPet), age(_age), weight(_weight), height(_height) {

}

Animal::Animal(const Animal &animal)
        : name(animal.name), color(animal.color), diet(animal.diet), habitat(animal.habitat),
          sounds(animal.sounds), isPet(animal.isPet), age(animal.age),
          weight(animal.weight), height(animal.height) {
    }


// Getters
string Animal::getName() const {
    return name;
}

string Animal::getColor() const {
    return color;
}

string Animal::getDiet() const {
    return diet;
}

string Animal::getHabitat() const {
    return habitat;
}

string Animal::getSounds() const {
    return sounds;
}

void Animal::make_sound() const{
    cout << sounds << endl;
}

bool Animal::getIsPet() const {
    return isPet;
}

int Animal::getAge() const {
    return age;
}

double Animal::getWeight() const {
    return weight;
}

double Animal::getHeight() const {
    return height;
}

// Setters
void Animal::setName(const string& newName) {
    name = newName;
}

void Animal::setColor(const string& newColor) {
    color = newColor;
}

void Animal::setDiet(const string& newDiet) {
    diet = newDiet;
}

void Animal::setHabitat(const string& newHabitat) {
    habitat = newHabitat;
}

void Animal::setSounds(const string& newSounds) {
    sounds = newSounds;
}

void Animal::setIsPet(bool newIsPet) {
    isPet = newIsPet;
}

void Animal::setAge(int newAge) {
    age = newAge;
}

void Animal::setWeight(double newWeight) {
    weight = newWeight;
}

void Animal::setHeight(double newHeight) {
    height = newHeight;
}

void Animal::printInfo() {
    cout << "Animal of unknown type :" << endl;
    cout << "Name: " << name << endl;
    cout << "Color: " << color << endl;
    cout << "Diet: " << diet << endl;
    cout << "Habitat: " << habitat << endl;
    cout << "Sounds: " << sounds << endl;
    cout << "Is Pet: " << "This animal is "<< (isPet ? "" : "not") << " a pet"<< endl;
    cout << "Age: " << age << " years" << endl;
    cout << "Weight: " << weight << " kg" << endl;
    cout << "Height: " << height << " meters" << endl;
}

