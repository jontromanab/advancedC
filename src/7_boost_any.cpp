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

int main(){
  AnyTesting1();
  return 0 ;
}
