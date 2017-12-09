/*
Compiler silently writes 4 functions if they are not explicitly declared:
  1. Copy constructor
  2. Copy Assignment Operator
  3. Destructor
  4. Default constructor(only if there is no constructor declared.)


class dog{
public:
  dog(const dog& rhs) {...}; //Member by member initialization
  dog& operator=(const dog& rhs){...}; //memeber by member copying
  dog(){...}; //1. Call base class's default constructor.
                   //2. Call data member's default constructor.
  ~dog(){...}; //1. Call base class's destructor;
                      //2. call data member's destructor;
}

1. they are public in inline
2. they are generated only if they are needed
*/

#include<iostream>

using namespace std;
class dog{
public:
  string m_name;
  dog(string name = "bob"){
    m_name = name;
    cout<<name<<" is born."<<endl;
  }
  ~dog(){cout<<m_name<<" is destroyed.\n"<<endl;}
};

class Collar{
public:
  Collar(string color){std::cout<<" Collar is born. \n";}
  Collar(){std::cout<<" Collar is born. \n";} //Without this default constructor the program will not compile
};

class Dog{
  Collar m_collar;
  //string& m_name; //Need to be initialized
};


//c++11 update
class Dog11{
  public:
  Dog11() = default;
  Dog11(string name){}
};

int main(){
  dog d1("Henry");
  dog d2;
  d2 = d1; //if there is string& m_name, the code will not compile. Because copy constructor will
  //try to copy reference, which is not possible

  Dog dog1;
}
