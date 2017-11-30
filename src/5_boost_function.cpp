/*
The function class allows to instantiate a pointer to a function with a flexible and clean syntax.
The underlying objects can be any fucntion or function pointer. The class has two syntax forms:
the preferred form and the portable form. The choice of the syntax depends on the compiler
we are using now preferred form

basic structure:
boost::function<return type(first variable type,...,last variable type)> f;

e.g. A boost function object which points to a function which returns a double and accepts two
double variables can be initialized with
boost::function<double (double, double)> f;

e.g. simple multiplicaiton function
double myMult(const double& x, const double& y){return x*y;}
can be assigned to the boost function pointer via
f = myMult;
we now can call f(x,y) just as if this is the original function. The maximum number of input variables
is currently 10


*****************************************
The passing of a function pointer to some other function, which does not know anything about
the implementation of the passed object. The passed functions will be the payofss of a call
and a put respectively.

*/

#include<iostream>
#include<boost/function.hpp>

double myCall(const double& spot, const double& strike){
  return std::max(spot-strike, 0.0);
}

double myPut(const double& spot, const double& strike){
  return std::max(strike-spot, 0.0);
}

void printRes(boost::function<double(double, double)> f, const double& x, const double& y){
  std::cout<<"Result: "<<f(x,y)<<std::endl;
}

void testingFunction1(){
  double s = 112.5, k = 105.0;
  boost::function<double (double, double)> funcPtr;

  funcPtr = myCall;
  printRes(funcPtr, s, k);

  funcPtr = myPut;
  printRes(funcPtr, s,k);
}

int main(){
  testingFunction1();
  return 0;
}
