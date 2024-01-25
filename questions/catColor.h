#include <iostream>
#include <string>

using namespace std;

#ifndef TRACECODE_CATCOLOR_H
#define TRACECODE_CATCOLOR_H


class Animal {
public:

   void makeSound() { cout << "animal sound" << endl; }

   virtual void food() { cout << "water" << endl; }

   virtual string getColor() = 0;
};

class Cat : public Animal {

private:
   string color;
public:

   Cat(string co = "white") : color(co) {}

   Cat(const Cat &a) {
      this->color = a.color;
   }

   void makeSound() { cout << "cat sound" << endl; }

   virtual void food() { cout << "mouse" << endl; }

   virtual string getColor() { return color; }

   Cat operator+ (Cat &other) {
      return Cat(getColor() + other.getColor());
   }

};

#endif //TRACECODE_CATCOLOR_H
