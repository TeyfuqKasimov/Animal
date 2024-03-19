// Copyright 2024 Kasimov T.

#ifndef C__USERS_TOFIK_DESKTOP_ANIMAL_INCLUDE_ANIMAL_H_
#define C__USERS_TOFIK_DESKTOP_ANIMAL_INCLUDE_ANIMAL_H_
#endif  // C__USERS_TOFIK_DESKTOP_ANIMAL_INCLUDE_ANIMAL_H_

#include <string>

class animal {
 public:
  enum Sex {
    male,
    female
  };

  animal(const double = 0, const Sex = male,
        const char* = nullptr, const size_t = 0);
  animal(const animal&);
  animal(animal&&);

  float getMass();
  Sex getSex();
  int   getAge();
  char* getColor();

  void setMass(const double);
  void setSex(const Sex = male);
  void setAge(const size_t);
  void setColor(const char*);

  virtual ~animal();

  virtual const char* WhatDoesSay() = 0;

 protected:
  double mass;
  Sex sex;
  char*  color;
  size_t age;
};

class Dog : public animal {
 public:
  enum Breed {
    beagle,
    boxer,
    bulldog,
    doberman,
    pug,
    poodle,
    dachshund,
    schnauzer,
    chihuahua,
    husky
  };

  Dog(const double = 0, const Sex = male,
        const char* = nullptr, const size_t = 0,
        const char* = nullptr, const Breed = beagle);
  Dog(const Dog&);
  Dog(Dog&&);
  const char*  WhatDoesSay() override;
  ~Dog();

  char* getName();
  Breed getRace();

  void setName(const char*);
  void setRace(const Breed);

  Dog& operator=(const Dog&);
  Dog& operator=(Dog&&);

 private:
  char* name;
  Breed breed;
};

class Fox : public animal {
 public:
  enum TypeFox {
    common,
    red,
    blackAndBrown,
    wood,
    arctic
  };
  Fox(const double = 0, const Sex = male,
      const char* = nullptr, const size_t = 0,
      const char* = nullptr, const int = 0, TypeFox temp_type = common);
  Fox(const Fox&);
  Fox(Fox&&);
  ~Fox();

  Fox& operator=(const Fox&);
  Fox& operator=(Fox&&);

  void eat();

  void setName(const char*);
  void setType(const TypeFox);

  char* getName();
  int getNumberRabbitsEaten();
  TypeFox getType();

  const char*  WhatDoesSay() override;

 private:
  char* name;
  int numberRabbitsEaten;
  TypeFox type;
};
