// Copyright 2024 Kasimov T.

#include <cstring>
#include <iostream>
#include "..\include\animal.h"

animal::animal(const double temp_mass, const Sex temp_sex,
        const char* temp_color, const size_t temp_age) {
    this->mass = temp_mass;
    this->age = temp_age;
    if (temp_color != nullptr) {
        size_t size = strlen(temp_color) + 1;
        this->color = new char[size];
        snprintf(this->color, size, "%s", temp_color);
    } else {
        this->color = nullptr;
    }
    this->sex = temp_sex;
}

animal::animal(const animal& temp) {
    if (&temp != this) {
        this->mass = temp.mass;
        this->age = temp.age;
        if (temp.color != nullptr) {
            size_t size = strlen(temp.color) + 1;
            this->color = new char[size];
            snprintf(this->color, size, "%s", temp.color);
        } else {
            this->color = nullptr;
        }
        this->sex = temp.sex;
    }
}

animal::animal(animal&& temp) {
    if (&temp != this) {
        this->mass = temp.mass;
        this->age = temp.age;
        if (temp.color != nullptr) {
            size_t size = strlen(temp.color) + 1;
            this->color = new char[size];
            snprintf(this->color, size, "%s", temp.color);
        } else {
            this->color = nullptr;
        }
        this->sex = temp.sex;
        temp.mass = 0;
        temp.age = 0;
        temp.sex = male;
        temp.color = nullptr;
    }
}

float animal::getMass()      { return mass;  }
int   animal::getAge()       { return age;   }
char* animal::getColor()     { return color; }
animal::Sex animal::getSex() { return sex; }

void animal::setMass(const double temp_mass)  { this->mass = temp_mass;   }
void animal::setSex(const Sex temp_sex)       { this->sex = temp_sex;     }
void animal::setAge(const size_t temp_age)    { this->age = temp_age;     }
void animal::setColor(const char* temp_color) {
    if (temp_color != nullptr) {
        size_t size = strlen(temp_color) + 1;
        this->color = new char[size];
        snprintf(this->color, size, "%s", temp_color);
    } else {
        this->color = nullptr;
    }
}

animal::~animal() {
    if (this->color != nullptr) {
        delete[] color;
    }
}

Dog::Dog(const double temp_mass, const Sex temp_sex,
        const char* temp_color, const size_t temp_age,
        const char* temp_name, const Breed temp_breed) :
            animal(temp_mass, temp_sex, temp_color, temp_age) {
    if (temp_name != nullptr) {
        size_t size = strlen(temp_name) + 1;
        this->name = new char[size];
        snprintf(this->name, size, "%s", temp_name);
    } else {
        this->name = nullptr;
    }
    this->breed = temp_breed;
}

Dog::Dog(const Dog& temp) {
    if (&temp != this) {
        this->mass = temp.mass;
        this->age = temp.age;
        if (temp.color != nullptr) {
            size_t size = strlen(temp.color) + 1;
            this->color = new char[size];
            snprintf(this->color, size, "%s", temp.color);
        } else {
            this->color = nullptr;
        }

        this->sex = temp.sex;
        if (temp.name != nullptr) {
            size_t size = strlen(temp.name) + 1;
            this->name = new char[size];
            snprintf(this->name, size, "%s", temp.name);
        } else {
            this->name = nullptr;
        }
        this->breed = temp.breed;
    }
}

Dog::Dog(Dog&& temp) {
    if (&temp != this) {
        this->mass = temp.mass;
        this->age = temp.age;

        if (temp.color != nullptr) {
            size_t size = strlen(temp.color) + 1;
            this->color = new char[size];
            snprintf(this->color, size, "%s", temp.color);
        } else {
            this->color = nullptr;
        }

        this->sex = temp.sex;

        if (temp.name != nullptr) {
            size_t size = strlen(temp.name) + 1;
            this->name = new char[size];
            snprintf(this->name, size, "%s", temp.name);
        } else {
            this->name = nullptr;
        }

        this->breed = temp.breed;
        temp.mass = 0;
        temp.age = 0;
        temp.sex = male;
        temp.breed = beagle;
        temp.color = nullptr;
        temp.name = nullptr;
    }
}

Dog::~Dog() {
    delete[] name;
}

char* Dog::getName()      { return name; }
Dog::Breed Dog::getRace() { return breed; }

void Dog::setName(const char* temp_name)  {
    if (temp_name != nullptr) {
        size_t size = strlen(temp_name) + 1;
        this->name = new char[size];
        snprintf(this->name, size, "%s", temp_name);
    } else {
        this->name = nullptr;
    }
}
void Dog::setRace(const Dog::Breed temp_breed) { this->breed = temp_breed; }

Dog& Dog::operator=(const Dog& temp) {
    if (&temp != this) {
        this->mass = temp.mass;
        this->age = temp.age;

        if (temp.color != nullptr) {
            size_t size = strlen(temp.color) + 1;
            this->color = new char[size];
            snprintf(this->color, size, "%s", temp.color);
        } else {
            this->color = nullptr;
        }

        this->sex = temp.sex;

        if (temp.name != nullptr) {
            size_t size = strlen(temp.name) + 1;
            this->name = new char[size];
            snprintf(this->name, size, "%s", temp.name);
        } else {
            this->name = nullptr;
        }

        this->breed = temp.breed;
    }

    return *this;
}

Dog& Dog::operator=(Dog&& temp) {
    if (&temp != this) {
        this->mass = temp.mass;
        this->age = temp.age;

        if (temp.color != nullptr) {
            size_t size = strlen(temp.color) + 1;
            this->color = new char[size];
            snprintf(this->color, size, "%s", temp.color);
        } else {
            this->color = nullptr;
        }

        this->sex = temp.sex;

        if (temp.name != nullptr) {
            size_t size = strlen(temp.name) + 1;
            this->name = new char[size];
            snprintf(this->name, size, "%s", temp.name);
        } else {
            this->name = nullptr;
        }

        this->breed = temp.breed;
        temp.mass = 0;
        temp.age = 0;
        temp.sex = male;
        temp.breed = beagle;
        temp.color = nullptr;
        temp.name = nullptr;
    }

    return *this;
}

const char* Dog::WhatDoesSay() {
    return "Woof-Woof";
}

Fox::Fox(const double temp_mass, const Sex temp_sex, const char* temp_color,
        const size_t temp_age, const char* temp_name,
        const int temp_rabitsCount, Fox::TypeFox temp_type) :
            animal(temp_mass, temp_sex, temp_color, temp_age) {
    if (temp_name != nullptr) {
        size_t size = strlen(temp_name) + 1;
        this->name = new char[size];
        snprintf(this->name, size, "%s", temp_name);
    } else {
        this->name = nullptr;
    }

    this->numberRabbitsEaten = temp_rabitsCount;
    this->type = temp_type;
}
Fox::Fox(const Fox& temp) {
    if (&temp != this) {
        this->mass = temp.mass;
        this->age = temp.age;

    if (temp.color != nullptr) {
        size_t size = strlen(temp.color) + 1;
        this->name = new char[size];
        snprintf(this->color, size, "%s", temp.color);
    } else {
        this->color = nullptr;
    }

        this->sex = temp.sex;

        if (temp.name != nullptr) {
            size_t size = strlen(temp.name) + 1;
            this->name = new char[size];
            snprintf(this->name, size, "%s", temp.name);
        } else {
            this->name = nullptr;
        }

        this->type = temp.type;
        this->numberRabbitsEaten = temp.numberRabbitsEaten;
    }
}

Fox::Fox(Fox&& temp) {
    if (&temp != this) {
        this->mass = temp.mass;
        this->age = temp.age;

        if (temp.color != nullptr) {
            size_t size = strlen(temp.color) + 1;
            this->color = new char[size];
            snprintf(this->color, size, "%s", temp.color);
        } else {
            this->color = nullptr;
        }

        this->sex = temp.sex;

        if (temp.name != nullptr) {
            size_t size = strlen(temp.name) + 1;
            this->name = new char[size];
            snprintf(this->name, size, "%s", temp.name);
        } else {
            this->name = nullptr;
        }

        this->type = temp.type;
        this->numberRabbitsEaten = temp.numberRabbitsEaten;
        temp.type = common;
        temp.name = nullptr;
        temp.numberRabbitsEaten = 0;
        temp.mass = 0;
        temp.age = 0;
        temp.sex = male;
        temp.color = nullptr;
    }
}

Fox::~Fox() {
    delete[] name;
}

Fox& Fox::operator=(const Fox& temp) {
    if (&temp != this) {
        this->mass = temp.mass;
        this->age = temp.age;

        if (temp.color != nullptr) {
            size_t size = strlen(temp.color) + 1;
            this->color = new char[size];
            snprintf(this->color, size, "%s", temp.color);
        } else {
            this->color = nullptr;
        }

        this->sex = temp.sex;

        if (temp.name != nullptr) {
            size_t size = strlen(temp.name) + 1;
            this->name = new char[size];
            snprintf(this->name, size, "%s", temp.name);
        } else {
            this->name = nullptr;
        }

        this->type = temp.type;
        this->numberRabbitsEaten = temp.numberRabbitsEaten;
    }

    return *this;
}

Fox& Fox::operator=(Fox&& temp) {
        if (&temp != this) {
        this->mass = temp.mass;
        this->age = temp.age;

        if (temp.color != nullptr) {
            size_t size = strlen(temp.color) + 1;
            this->color = new char[size];
            snprintf(this->color, size, "%s", temp.color);
        } else {
            this->color = nullptr;
        }

        this->sex = temp.sex;

        if (temp.name != nullptr) {
            size_t size = strlen(temp.name) + 1;
            this->name = new char[size];
            snprintf(this->name, size, "%s", temp.name);
        } else {
            this->name = nullptr;
        }

        this->type = temp.type;
        this->numberRabbitsEaten = temp.numberRabbitsEaten;
        temp.type = common;
        temp.name = nullptr;
        temp.numberRabbitsEaten = 0;
        temp.mass = 0;
        temp.age = 0;
        temp.sex = male;
        temp.color = nullptr;
    }

    return *this;
}

void Fox::eat() { numberRabbitsEaten++; }

void Fox::setName(const char* temp_name) {
    if (temp_name != nullptr) {
            size_t size = strlen(temp_name) + 1;
            this->name = new char[size];
            snprintf(this->name, size, "%s", temp_name);
        } else {
            this->name = nullptr;
        }
}
void Fox::setType(const Fox::TypeFox temp_type) { this->type = temp_type; }

char* Fox::getName() { return name; }
int Fox::getNumberRabbitsEaten() { return numberRabbitsEaten; }
Fox::TypeFox Fox::getType() { return type; }

const char* Fox::WhatDoesSay() {
    switch (type) {
    case 0:
        return "Ring-ding-ding-ding-dingeringeding";
        break;
    case 1:
        return "Gering-ding-ding-ding-dingeringeding";
        break;
    case 2:
        return "Wa-pa-pa-pa-pa-pa-pow";
        break;
    case 3:
        return "Hatee-hatee-hatee-ho";
        break;
    case 4:
        return "Joff-tchoff-tchoffo-tchoffo-tchoff";
        break;

    default:
        return "123";
        break;
    }
}
