//
// Created by Lightii Chen on 2023/12/8.
//

#include <iostream>
#include <string>
using namespace std;


#ifndef APPLE_COLOR
#define APPLE_COLOR


class Fruit {

private:
   string color;

public:

   void setColor(string value) { color = value; };
   string getColor() const { return color; };
   virtual void taste() = 0;
   void printInfo() { cout << color << endl; };

   virtual void printData() {
      cout << color << endl;
   }

   virtual ~Fruit(){}
};


class Apple : public Fruit {

private:
   string cultivar;

public:

   Apple(string co = "red", string cu = "Fuji") : cultivar(cu) { setColor(co); };
   Apple(const Apple &a) {

      setColor(a.getColor());
      cultivar = a.cultivar;
   };
   ~Apple() {};

   void taste() { cout << "sweet" << endl; };
   void setCultivar(string cu) { cultivar = cu; };
   void setCultivar(string cu, string co) {
      cultivar = cu;
      setColor(co);
   };

   void printInfo() { cout << cultivar << endl; };
   void printData() override { cout << cultivar << endl; };
};


//void execute() {
//
//   Apple apple;
//   apple.setCultivar("McIntosh", "green");
//
//   Fruit *p1 = new Apple();
//   Fruit *p2 = new Apple(apple);
//   Apple *p3 = new Apple();
//
//   p3->setColor("yellow");
//   p3->setCultivar("McIntosh");
//   p1->printInfo();
//   p2->printInfo();
//   p3->printInfo();
//   p1->printData();
//   p2->printData();
//   p3->printData();
//}


#endif

