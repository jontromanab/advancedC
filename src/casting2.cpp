#include<iostream>
using namespace std;

class dog{
public:
  virtual ~dog(){}
  virtual void bark(){}
};

class yellowdog : public dog{
  int age;
public:
  void bark(){cout<<"woof "<<endl;}
};


int main(){
  dog* pd = new dog();

  //yellowdog * py = dynamic_cast<yellowdog*>(pd);
  //yellowdog * py = static_cast<yellowdog*>(pd);
  yellowdog * py = dynamic_cast<yellowdog*>(pd);
  if(py)
    py->bark();
  py->bark();
  cout<<"py = "<<py<<endl;
  cout<<"pd = "<<pd<<endl;
}
