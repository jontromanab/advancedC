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


*****************************************
Calling a boost function object with has not been assigned to another function will result in exception. It is possible to check if the
function object is a NULL pointer:
boost::function<double (double)>f;
if(!f) //error, do something
These are all legal:
boost::function<double (double)>f(myFunc);

boost::function<double (double)> f;
f = myFunc;

boost::function<double (double)>f;
f = &myFunc;

//by standard function pointer
double (*myMultPtr)(double x, double y);
myMultPtr = &myMult;


definition of a class member function pointer. consider a class X with a function double X::myFunc(double x).
we will be interested in extracting the member function by declaring a function pointer to it. This can be achieved by
boost's fucntion pointer by passing some ref to the function (an object pointer or an object ref).
boost::function<double (X*, double)> xMembFunc;
xMembFunc = & X::myFunc

XmembFunc can be called via:
xMembFunc(&myX,x)

we can do this by boost::bind
*/

#include<iostream>
#include<boost/function.hpp>
#include<boost/bind.hpp>

double myCall(const double& spot, const double& strike){
  return std::max(spot - strike, 0.0);
}

double myPut(const double& spot, const double& strike){
  return std::max(strike - spot, 0.0);
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

class FunctionClass{
private:
  double a_;
public:
  FunctionClass(const double& a):a_(a){}

  double multWithA(const double& x)const{return a_*x;}
  double operator()(const double& x) const{return a_*x;}
};

void testingFunction2(){
  FunctionClass myClass(2.0);
  double x = 12.0;
  //intialize function pointer to a class function
  boost::function<double(FunctionClass*, double)> funcPtr, functPtr1;
  //assign the multWithA function and the operator
  funcPtr = &FunctionClass::multWithA;
  functPtr1 = &FunctionClass::operator ();

  std::cout<<myClass.multWithA(x)<<std::endl;
  std::cout<<funcPtr(&myClass,x) <<std::endl;
  std::cout<<functPtr1(&myClass,x)<<std::endl;

  //bind the function with the class instance
  boost::function<double (double)> funcPtrnew;
  funcPtrnew = boost::bind(funcPtr, &myClass, _1);

  std::cout<<funcPtrnew(x)<<std::endl;
}

//In some cases it is expensive to have boost::function clone a function object. In that case. it
//is possible to request that boost keeps a ref to the function object by calling boost::ref function

double myMult(const double& x, const double& y){
  return x*y;
}

void testingFunction3(){
  boost::function<double (double, double)> myMultPtr;
  myMultPtr = boost::ref(myMult);
  std::cout<<myMultPtr(3.0, 3.0)<<std::endl;
}

int main(){
  testingFunction1();
  testingFunction2();
  testingFunction3();
  return 0;
}





