//Calling virtual function in constructor or destructor (avoid unless static function)

#include<iostream>
#include<memory>
using namespace std;

class Dog{
public:
  Dog() {cout<<"Dog born."<<endl;}//bark().. We dont need this. calling main class functions before base class's constructor}
  virtual void bark(){cout<<"I am just a dog."<<endl;}
  void seeCat(){bark();}
};

class YellowDog : public Dog{
public:
  YellowDog(){cout<<"Yellow dog is born"<<endl;}
  virtual void bark(){cout<<"I am a yellow dog"<<endl;}

};


int main(){
  YellowDog d;
  d.seeCat();
  return 0;
}
