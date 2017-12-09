#include<iostream>

using namespace std;
//const used with functions
class Dog{
  int age;
  string name;
public:
  Dog() {age =3; name = "dummy";}
  // If we take by const, then we cannot change local variable i
  //void setAge(int& a){age = a; a++;}
  void setAge(const int& a){age = a;}
  //void setAge(const int a){age = a;} //Not very useful as setAge is making a copy of local variable i
  //which is becoming const. If we overload it with void setAge(int a), the compiler will show message that
  //it can be overloaded


  //const return value
  const string& getName() {return name;} //sending by reference, so it cannot be changed
  //const string getName() {return name;} //const is

  //const function
  void printDogName() const {cout<<name<<" const"<<endl; }
  //void printDogName() const {cout<<name<<" const"<<endl; age++;} // It is not valid.
  //void printDogName() const {cout<<getName()<<" const"<<endl; } //It is not valid. It can only call
  //another constant function
  void printDogName() {cout<<name<<" non const"<<endl; } // can be overloaded
};

int main(){
  Dog d;

  int i = 9;
  d.setAge(i);
  cout<<i<<endl;
  const string& n = d.getName();
  cout<<d.getName()<<endl;
  cout<<n<<endl;
  d.printDogName();

  const Dog d2;
  d2.printDogName(); //This will call the const function
}
