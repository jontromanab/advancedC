//Use virtual destructor in polymorphic base classes
//without the virtual destructor, the Dog is only destroyed, not the yellowdog

#include<iostream>
#include<memory>
using namespace std;

class Dog{
public:
  virtual ~Dog(){cout<<"Dog destroyed"<<endl;}
  virtual void bark(){}
};

class YellowDog : public Dog{
public:
  ~YellowDog(){cout<<"Yellow dog destroyed"<<endl;}
};

class DogFactory{
public:
  static Dog* createYellowDog(){return  (new YellowDog());}
  static std::shared_ptr<Dog> createBlueDog(){
    return (shared_ptr<YellowDog>(new YellowDog()));
  }
  //...create other dogs
};

int main(){
  Dog* pd = DogFactory::createYellowDog();
  //... Do something with pd;
  shared_ptr<Dog> pd1 = DogFactory::createBlueDog();

  delete pd;
  return 0;
}
