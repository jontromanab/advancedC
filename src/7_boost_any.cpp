/*
The any class can take any value. We can assign any variable=> a double, string, std::vector<double>

*/

#include<boost/any.hpp>
#include<vector>
#include<iostream>

void callAny(boost::any x);

void AnyTesting1(){
  boost::any myvar;

  myvar = 1.1;
  myvar = std::string("1.1");
  myvar = std::vector<double>(3);

  double x = 1.1;
  callAny(x);
}

void callAny(boost::any x){
  //Do nothing
}

/*
The type of any variable can be checked with the type() function against the standard typeid(T) function.
To retrieve the original variable back, use the any_Cast function

T* ptrMyT = boost::any_cast<T>(&myAny);

*/

void AnyTesting2(){
  boost::any myAny;
  double myDbl(1.1);
  myAny = myDbl;
  bool isDbl = myAny.type() == typeid(double);
  std::cout<<"Is double: "<<isDbl<<std::endl;
  bool isString = myAny.type() ==typeid(std::string);
  std::cout<<"Is String: "<<isString<<std::endl;

  double* ptrMyDbl = boost::any_cast<double>(&myAny);
  if(ptrMyDbl!=NULL) std::cout<<"My double: "<<*ptrMyDbl<<std::endl;

  int* ptrMyInt = boost::any_cast<int>(&myAny);
  if(ptrMyInt == NULL) std::cout<<"Cast failed"<<std::endl;
}


int main(){
  AnyTesting1();
  AnyTesting2();
  return 0 ;
}
