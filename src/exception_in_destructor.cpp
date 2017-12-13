//prevent execeptions from leaving destructors.

#include<iostream>

using namespace std;

class dog{
public:
  string m_name;
  dog(string name){m_name = name;
                   cout<<name<<" is born."<<endl;}
  ~dog(){cout<<m_name<<" is distroyed.\n"<<endl;}//throw 20;}
  void bark(){}
};

int main(){
  try{
    dog dog1("Henry");
    dog dog2("Bob");
    //throw 20;
    dog1.bark();
    dog2.bark();
  }catch(int e){
    cout<<e<<" is caught"<<endl;
  }
  return 0;
}

//Bob and Henry will be destroyed before the catch as, they are stored on a stack
// Add flow exception to the dog destructor

/* we shoudl not throw exception from destructor
soltuion 1: Destructor swallow the exception.
~dog(){
try{
 //Enclose all the exception prone code here
 } catch(MYexception e){
 //catch exception
 }
}


solution2: collect all the exceptions in a separate function

*/
