//
//  Zoo.cpp
//  ㄹㅇㅇ
//
//  Created by Andoni on 12/01/2024.
//

#include "Zoo.hpp"
#include "KNNDouble.hpp"
#include "KNNString.hpp"


int Zoo::MAX_CAPACITY = 15;

Zoo::Zoo() : name("Best Zoo Ever") {
}

Zoo::Zoo(string _name) : name(_name) {
}

Zoo::Zoo(const Zoo &copyZoo, const vector<Animal*>& animals)
        : name(copyZoo.name), animals(animals) {
}



void Zoo::listAnimals() const {
    cout << "Animals in the Zoo '" << name << "':" << endl;

    for (Animal *animal : animals) {
        animal->printInfo();
        cout << "----------------------" << endl;
    }
}


void Zoo::addAnimal(Animal* newAnimal) {
    if (animals.size() >= MAX_CAPACITY) {
        cout << "Zoo at maximum capacity. Cannot add more animals." << endl;
        return;
    }

    auto it = lower_bound(animals.begin(), animals.end(), newAnimal, compareAnimalNames);
    if (it != animals.end() && (*it)->getName() == newAnimal->getName()) {
        cout << "An animal with the name '" << newAnimal->getName() << "' already exists in the zoo." << endl;
        return;
    }

    animals.insert(it, newAnimal);
}

int Zoo::searchAnimalByName(const string& animalName) const {

    auto it = lower_bound(animals.begin(), animals.end(), animalName,
                          [](const Animal* a, const string& name) {
                              return a->getName() < name;
                          });

    if (it != animals.end() && (*it)->getName() == animalName) {
        return distance(animals.begin(), it);
    } else {
        return -1;
    }
}



void Zoo::removeAnimalByName(const string &animalName) {
    auto removeIt = remove_if(animals.begin(), animals.end(),
                              [animalName](const Animal* a) {
                                  return a->getName() == animalName;
                              });

    for (auto it = removeIt; it != animals.end(); ++it) {
        delete *it;
    }
    animals.erase(removeIt, animals.end());

    if (removeIt == animals.begin()) {
        cout << "Animal with name '" << animalName << "' not found in the zoo." << endl;
    }
}

bool Zoo::compareAnimalNames(const Animal* a1, const Animal* a2) {
    return a1->getName() < a2->getName();
}

void Zoo::setName(string newName) {
    name = newName;
}

string Zoo::getName() const {
    return name;
}


double Zoo::averageAgeForType(const string& animalType) {
    vector<Animal*> animalsOfType;

    copy_if(animals.begin(), animals.end(), back_inserter(animalsOfType),
                 [animalType](const Animal* a) {
                     if (animalType == "Mammal" && dynamic_cast<const Mammal*>(a)) {
                         return true;
                     } else if (animalType == "Bird" && dynamic_cast<const Bird*>(a)) {
                         return true;
                     } else if (animalType == "Reptile" && dynamic_cast<const Reptile*>(a)) {
                         return true;
                     }
                     return false;
                 });

    if (!animalsOfType.empty()) {
        double totalAge = accumulate(animalsOfType.begin(), animalsOfType.end(), 0.0,
                                          [](double sum, const Animal* a) {
                                              return sum + a->getAge();
                                          });
        return totalAge / animalsOfType.size();
    } else {
        return -1.0;
    }
}



void Zoo::predictTypeWithKNN(Animal* newAnimal, int k, const string& infoType) {
    vector<int> neighbors;
    if (infoType == "numerical") {
        // Prepare trainData (weights and heights of existing animals)
        vector<pair<double, double>> trainData;
        for (const Animal* animal : animals) {
            if (const Mammal* mammal = dynamic_cast<const Mammal*>(animal)) {
                trainData.push_back(make_pair(mammal->getWeight(), mammal->getHeight()));
            } else if (const Bird* bird = dynamic_cast<const Bird*>(animal)) {
                trainData.push_back(make_pair(bird->getWeight(), bird->getHeight()));
            } else if (const Reptile* reptile = dynamic_cast<const Reptile*>(animal)) {
                trainData.push_back(make_pair(reptile->getWeight(), reptile->getHeight()));
            }
        }

        // Prepare target (weight and height of the new animal)
        pair<double, double> target;
        if (const Mammal* mammal = dynamic_cast<const Mammal*>(newAnimal)) {
            target = make_pair(mammal->getWeight(), mammal->getHeight());
        } else if (const Bird* bird = dynamic_cast<const Bird*>(newAnimal)) {
            target = make_pair(bird->getWeight(), bird->getHeight());
        } else if (const Reptile* reptile = dynamic_cast<const Reptile*>(newAnimal)) {
            target = make_pair(reptile->getWeight(), reptile->getHeight());
        }

        // Use KNNDouble for numerical information
        KNNDouble knnDouble(k);
        neighbors = knnDouble.findNearestNeighbours(trainData, target);
        
        // Now, 'neighbors' contains the similarity values and the corresponding weights and heights of the k nearest neighbors
        // You can use this information for further processing
    } else if (infoType == "categorical") {
        // Prepare trainData (color, diet, habitat, and sound of existing animals)
        vector<vector<string>> trainData;
        for (const Animal* animal : animals) {
            trainData.push_back({animal->getColor(), animal->getDiet(), animal->getHabitat(), animal->getSounds()});
        }

        // Prepare target (color, diet, habitat, and sound of the new animal)
        vector<string> target = {newAnimal->getColor(), newAnimal->getDiet(), newAnimal->getHabitat(), newAnimal->getSounds()};

        // Use KNNString for categorical information
        KNNString knnString(k);
        neighbors = knnString.findNearestNeighbours(trainData, target);

        // Now, 'neighbors' contains the similarity values and the corresponding categorical features of the k nearest neighbors
        // You can use this information for further processing
    } else {
        // Handle unsupported infoType
        cerr << "Unsupported information type: " << infoType << endl;
    }
    for (size_t t=0;t<neighbors.size();t++){
        cout << neighbors[t]<< endl;
    }

}
