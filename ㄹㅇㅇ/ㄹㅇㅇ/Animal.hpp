//
//  Animal.hpp
//  ㄹㅇㅇ
//
//  Created by Andoni on 12/01/2024.
//

#ifndef Animal_hpp
#define Animal_hpp

#include <iostream>
#include <string>

using namespace std;

class Animal {

public:
    Animal();
    Animal( string _name, string _color, string _diet, string _habitat, string _sounds, bool _isPet, int _age, double _weight, double _height);
    Animal(Animal const &animal);
    virtual void printInfo();

    string getName() const;
    string getColor() const;
    string getDiet() const;
    string getHabitat() const;
    string getSounds() const;
    bool getIsPet() const;
    int getAge() const;
    double getWeight() const;
    double getHeight() const;
    void make_sound() const;

    void setName(const string &newName);
    void setColor(const string &newColor);
    void setDiet(const string &newDiet);
    void setHabitat(const string &newHabitat);
    void setSounds(const string &newSounds);
    void setIsPet(bool newIsPet);
    void setAge(int newAge);
    void setWeight(double newWeight);
    void setHeight(double newHeight);
    

protected:
    string name;
    string color;
    string diet;
    string habitat;
    string sounds;
    bool isPet;
    int age;
    double weight;
    double height;
};
#endif /* Animal_hpp */
