// Copyright 2024 Kasimov T.

#include <iostream>
#include <string>
#include "..\include\animal.h"

const char* GetTypeFox(const Fox::TypeFox& temp) {
    switch (temp) {
        case 0:
            return "common";
        case 1:
            return "red";
        case 2:
            return "blackAndBrown";
        case 3:
            return "wood";
        case 4:
            return "arctic";
        default:
            return "-";
    }
}

const char* GetRaceDog(const Dog::Breed& temp) {
    switch (temp) {
        case 0:
            return "beagle";
            break;
        case 1:
            return "boxer";
        case 2:
            return "bulldog";
        case 3:
            return "doberman";
        case 4:
            return "pug";
        case 5:
            return "poodle";
        case 6:
            return "dachshund";
        case 7:
            return "schnauzer";
        case 8:
            return "chihuahua";
        case 9:
            return "husky";
        default:
            return "-";
            break;
    }
}

int main() {
    Dog dog1(2.1, animal::male, "Yellow", 5, "George", Dog::bulldog);

    Fox fox(2.2, animal::female, "Red", 8, "Haskey", 0, Fox::red);

    std::cout << "Dog1:" << std::endl <<
                    "Age:" << dog1.getAge() << "|Name:" << dog1.getName() <<
                    "|Race:" << GetRaceDog(dog1.getRace()) << "|Color:" <<
                    dog1.getColor() << "|Age:" << dog1.getAge() <<
                    "|Mass:" << dog1.getMass() << "|He say:" <<
                    dog1.WhatDoesSay() << std::endl << std::endl;

    Dog dog2(dog1);
    std::cout << "Dog2:(Before changing)" << std::endl <<
                "Age:" << dog2.getAge() << "|Name:" << dog2.getName() <<
                "|Race:" << GetRaceDog(dog2.getRace()) << "|Color:" <<
                dog2.getColor() << "|Age:" << dog2.getAge() <<
                "|Mass:" << dog2.getMass() << "|He say:" <<
                dog2.WhatDoesSay() << std::endl << std::endl;

    dog2.setAge(7);
    dog2.setColor("Blue");
    dog2.setMass(2.6);
    dog2.setName("Zhenya");
    dog2.setRace(Dog::dachshund);
    dog2.setSex(Dog::male);

    std::cout << "Dog2:(After changing)" << std::endl <<
                "Age:" << dog2.getAge() << "|Name:" << dog2.getName() <<
                "|Race:" << GetRaceDog(dog2.getRace()) << "|Color:" <<
                dog2.getColor() << "|Age:" << dog2.getAge() <<
                "|Mass:" << dog2.getMass() << "|He say:" <<
                dog2.WhatDoesSay() << std::endl << std::endl;

    Fox fox1(2.3, animal::male, "Red", 11, "Sanya", 0, Fox::arctic);
    std::cout << "Fox1:" << std::endl <<
                "Age:" << fox1.getAge() << "|Name:" << fox1.getName() <<
                "|Race:" << GetTypeFox(fox1.getType()) << "|Color:" <<
                fox1.getColor() << "|Age:" << fox1.getAge() <<
                "|Mass:" << fox1.getMass() << "|He say:" <<
                fox1.WhatDoesSay() << "|NumberRabbitsEaten:"<<
                fox1.getNumberRabbitsEaten() << std::endl << std::endl;
    Fox fox2;
    fox2 = fox1;
    std::cout << "Fox2:(Before changing)" << std::endl <<
                "Age:" << fox2.getAge() << "|Name:" << fox2.getName() <<
                "|Race:" << GetTypeFox(fox2.getType()) << "|Color:" <<
                fox2.getColor() << "|Age:" << fox2.getAge() <<
                "|Mass:" << fox2.getMass() << "|He say:" <<
                fox2.WhatDoesSay() << "|NumberRabbitsEaten:"<<
                fox2.getNumberRabbitsEaten() << std::endl << std::endl;
    fox2.setAge(4);
    fox2.setColor("Black");
    fox2.setMass(2);
    fox2.setName("Ira");
    fox2.setType(Fox::blackAndBrown);
    fox2.setSex(Dog::female);
    fox2.eat();

    std::cout << "Fox2:(After changing)" << std::endl <<
                "Age:" << fox2.getAge() << "|Name:" << fox2.getName() <<
                "|Race:" << GetTypeFox(fox2.getType()) << "|Color:" <<
                fox2.getColor() << "|Age:" << fox2.getAge() <<
                "|Mass:" << fox2.getMass() << "|He say:" <<
                fox2.WhatDoesSay() << "|NumberRabbitsEaten:"<<
                fox2.getNumberRabbitsEaten() << std::endl << std::endl;

    return 0;
}
