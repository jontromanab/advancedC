/*
The bind class is able to bind any function object argument to a specific value or route input
arguments into arbitary positions.
works for functions , function objects and function pointers

e.g.
- You have a fucntion which accepts many arguments, and you would like to work with one variable
only, keeping the others constant

- you are given a function which you cann not modify and you would like the call the function with
the parameters being in a different, probably more intutive order.

boost bind refers to input variables by their number with a _ prefix in the order they are passed to the
fucntion. e.g _1 denotes the first argument of the function
e.g indicatorFunc

double indicatorFunc(const double& x, const double& a, const double& b)

returns 1, if x in range of a and b, 0 otherwise. suppose we want to work a lot on this function in the
interval [-1,1]. we dont want indicatorFunc(x, -1,1)

boost::function<double (double)> indPmOne;
double a = -1.0, b = 1.0l
indPmOne = boost::bind<indicatorFunc, _1,a,b) //The first param x should stay as it is. The rest param are fixed

indPmOne(x)


*/

#include<boost/bind.hpp>
#include<boost/function.hpp>
#include<iostream>

double indicatorFunc(const double& x, const double& a, const double& b){
  if(x>=a && x<=b) return 1.0;
  else return 0.0;
}

void testingBind1(){
  double a=-1.0, b = 1.0;
  boost::function<double (double)> ind;
  ind = boost::bind(indicatorFunc,_1, a,b);
  std::cout<<ind(0.5)<<std::endl;
  std::cout<<ind(5.0)<<std::endl;
}

//if we want some other order of variables
void testingBind2(){
  double x = 1.01, a = -1.0, b = 1.0;
  std::cout<<"Original function: "<<indicatorFunc(x, a,b)<<std::endl;
  boost::function<double (double, double, double) > indReordered;
  indReordered = boost::bind(indicatorFunc, _3,_1,_2);//(a,b,x)
  std::cout<<"Reordered arrangements: "<<indReordered(a,b,x)<<std::endl;
}

int main(){
  testingBind1();
  testingBind2();
  return 0;
}














