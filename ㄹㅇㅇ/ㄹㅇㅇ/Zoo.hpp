//
//  Zoo.hpp
//  ㄹㅇㅇ
//
//  Created by Andoni on 12/01/2024.
//

#ifndef Zoo_hpp
#define Zoo_hpp

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Animal.hpp"
#include "Mammal.hpp"
#include "Bird.hpp"
#include "Reptile.hpp"

using namespace std;

class Zoo {
public:
    Zoo();
    Zoo(string name);
    Zoo(const Zoo &copyZoo, const vector<Animal*>& animals);

    void listAnimals() const;
    void addAnimal(Animal* newAnimal);
    int searchAnimalByName(const string& ) const;
    void removeAnimalByName(const string& );
    double averageAgeForType(const string &animalType);

protected:
    string name;
    static int MAX_CAPACITY;
    vector<Animal*> animals;

    void setName(string newName);
    string getName() const;
    static bool compareAnimalNames(const Animal* a1, const Animal* a2);
public:
    void predictTypeWithKNN(Animal* newAnimal, int k, const string& infoType);

};

#endif /* Zoo_hpp */
