//
// Created by Lightii Chen on 2023/12/11.
//

#ifndef TRACECODE_REDTEA_H
#define TRACECODE_REDTEA_H

class RedTea{

protected:
   string _name = "Unknown";
   int _price = 0;
   double _content = 0;

public:

   RedTea() = default;
   RedTea(string name, int price, double content): _name(name), _price(price), _content(content){}

   virtual ~RedTea(){};
   virtual void dilute() = 0;

   int get_price() const {
      return _price;
   }

   string get_name() const {
      return _name;
   }

   double get_alcohol_content() const {
      return _content;
   }
};

class LongIsland: public RedTea {
public:
   LongIsland() = default;
   LongIsland(string name, int price, double alcohol_content): RedTea(name, price, alcohol_content){}

   ~LongIsland() = default;

   void dilute() override {
      this->_content *= 0.7;
   }
};

class NewBloodyMary;
static NewBloodyMary CreateNewBloodyMary(string name, int price, double content);

class NewBloodyMary: public RedTea {
   friend NewBloodyMary CreateNewBloodyMary(string name, int price, double content);

private:
   NewBloodyMary(string name, int price, double content): RedTea(name, price, content){}

public:
   NewBloodyMary() = default;
   ~NewBloodyMary() = default;

   void dilute() override {
      this->_content *= 0.95;
   }

   static NewBloodyMary* CreateNewBloodyMaryPtr(string name, int price, double content) {
      return new NewBloodyMary(name, price, content);
   }

   NewBloodyMary& operator=(const NewBloodyMary& other) {
      this->_name = other._name;
      this->_price = other._price;
      this->_content = other._content;
      return *this;
   }

   NewBloodyMary operator+(const NewBloodyMary& other) {
      return NewBloodyMary(this->_name, this->_price + other._price, (this->_content + other._content)/2);
   }
};

static NewBloodyMary CreateNewBloodyMary(string n, int p, double c) {
   return NewBloodyMary(n, p, c);
}

class Order{
private:
   std::vector<RedTea*> vec;
public:
   Order() = default;
   ~Order(){
      for (int i = 0; i< vec.size(); i++) {
         delete vec[i];
      }
   }

   void append_alcohol(RedTea* alcohol) {
      vec.push_back(alcohol);
   }

   int get_total_price(){
      int total = 0;
      for(int i = 0; i< vec.size(); i++) {
         total += vec[i]->get_price();
         cout << total << endl;
      }

      return total;
   }
};

#endif //TRACECODE_REDTEA_H
