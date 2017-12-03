/*
Boost optional provides a framework to deal with objects whose initialization is optional.
An example is a function which returns an object whose construcntion has either been successful or not.
There is existing framework to check if the object has been initialized or not.
Initialization of an optional object is performed by:

  boost::optional<T> opt(t);

where t is an instance of the template class T. The variable opt now has a value of 1. If opt is not
initialized, it has value of 0;
We can check if opt has one of the values before processing. We can also check against NULL.
The class object passed tp optional can be dereferenced in various ways. Example functions which return objects
or pointers to objects are:

get(): returns the object
operator *(): returns the object
get_ptr() : returns a pointer to the object

*/


#include<iostream>
#include<boost/optional.hpp>
#include<boost/optional/optional_io.hpp>
#include<boost/date_time/gregorian/gregorian.hpp>


void testingOptional1(){
  boost::optional<double> myOpt1;
  double b = 1.1;
  boost::optional<double> myOpt2(b);

  std::cout<<myOpt1<<std::endl;
  std::cout<<myOpt2<<std::endl;

  /*if(myOpt1 == NULL){
    std::cout<<"Empty Object"<<std::endl;
  }
  else{
    std::cout<<*myOpt1<<std::endl;
  }

  if(myOpt2 == NULL){
    std::cout<<"Empty Object"<<std::endl;
  }
  else{
    std::cout<<myOpt2.get()<<std::endl;
  }*/
}

class SimpleSettleMentClass{
private:
  boost::gregorian::date d_;
  boost::optional<int> settlementDays_;

public:
  SimpleSettleMentClass(const boost::gregorian::date& d):d_(d){
    //default constructor with settlement date given
  };
  SimpleSettleMentClass(const boost::gregorian::date &d, const int& settlementDays):d_(d),settlementDays_(settlementDays){
    //constructor with initial date + settlement days
  };

  boost::gregorian::date settlement() const{
    if(settlementDays_){
      return d_ + boost::gregorian::days(*settlementDays_);
    }
    else{
      return d_;
    }
  }

  int settlementDays() const{
    if(settlementDays_){
      return *settlementDays_;
    }
    else{
      return 0;
    }
  }
};

void testingOptional2(){
  boost::gregorian::date d1(2009, 9,20);
  SimpleSettleMentClass settlement1(d1);
  SimpleSettleMentClass settlement2(d1,3); //advance settlement by 3 days

  std::cout<<"Settlement 1: "<<settlement1.settlement()<<std::endl;
  std::cout<<"Settlement 2: "<<settlement2.settlement()<<std::endl;
  std::cout<<"Settlement 1 Days: "<<settlement1.settlementDays()<<std::endl;
  std::cout<<"Settlement 2 Dyas: "<<settlement2.settlementDays()<<std::endl;
}


int main(){
  testingOptional1();
  testingOptional2();
  return 0;
}
