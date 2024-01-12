#include "Zoo.hpp"
#include "Mammal.hpp"
#include "Bird.hpp"
#include "Reptile.hpp"
#include <iostream>

int main() {
    // Create a Zoo
    Zoo myZoo("MyZoo");

    // Add some animals to the Zoo
    myZoo.addAnimal(new Mammal("Lion", "Brown", "Yellow", "Carnivore", "Savannah", "Roar", false, 5, 150, 3.5));
    myZoo.addAnimal(new Mammal("Elephant", "Gray", "Gray", "Herbivore", "Jungle", "Trumpet", false, 10, 5000, 8.0));
    myZoo.addAnimal(new Bird("Parrot", "Colorful", 0.5, "Herbivore", "Tropical", "Squawk", false,3, 2, 0.1));
    myZoo.addAnimal(new Bird("Penguin", "Black and White", 0.6, "Piscivore", "Polar", "Honk", false,4, 3, 0.6));
    myZoo.addAnimal(new Reptile("Snake", "Green", "Scales", "Carnivore", "Desert", "Hiss", false, 1, 2.0, 0.2));
    myZoo.addAnimal(new Reptile("Turtle", "Brown", "Shell", "Herbivore", "Aquatic", "None", false, 5, 5.0, 0.3));

    // Display the list of animals in the Zoo
    myZoo.listAnimals();

    // Test KNNDouble for numerical information
    Mammal newMammal("NewMammal", "Yellow", "Brown", "Herbivore", "Savannah", "Chirp", false, 2, 200, 4.0);
    myZoo.predictTypeWithKNN(&newMammal, 3, "numerical");

    // Test KNNString for categorical information
    Bird newBird("NewBird", "Red", 0.3, "Omnivore", "Forest", "Tweet", false,3, 1, 0.05);
    myZoo.predictTypeWithKNN(&newBird, 3, "categorical");

    return 0;
}
