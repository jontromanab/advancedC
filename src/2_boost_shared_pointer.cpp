#ifndef TEST_CLASS_A
#define TEST_CLASS_A

#include<iostream>
#include<boost/shared_ptr.hpp>

class A
{
private:
  double myValue_;
public:
  A(const double& myValue):myValue_(myValue){
    std::cout<<"Constructor of A"<<std::endl;
  }
  ~A(){
    std::cout<<"Destructor of A with value "<<myValue_<<std::endl;
  }
  double getValue() const{return myValue_;}

  //void testSharedPtrA();


};

//The usual way to allocate object of A on the heap by dyanmically allocating memory space
// and later calling delete
void testSharedPtrA(){
  std::cout<<"Calling test A"<<std::endl;
  A* ptr_myA = new A(1.0);
  delete ptr_myA;
}

//Behaviours of raw pointers for exception
void testSharedPtrB(){
  std::cout<<"Calling test B"<<std::endl;
  A* ptr_myA = new A(1.0);
  throw "Error occured for class A.";
  delete ptr_myA;
}

//By smart pointer
void testSharedPtrC(){
  std::cout<<"Calling test C"<<std::endl;
  boost::shared_ptr<A> bptr_myA(new A(1.0));
}

//Assigning ownership of usual pointer to shared pointer
//raw pointer as an argument in the constructor of shared ptr
void testSharedPtrD(){
  std::cout<<"Calling test D"<<std::endl;
  A* ptr_myA = new A(5.0);
  boost::shared_ptr<A> bptr_myA(ptr_myA);
  std::cout<<bptr_myA->getValue()<<std::endl;
}

//Behavior of boost::shared_ptr in exception
//still memory leak
void testSharedPtrE(){
  std::cout<<"Calling test E"<<std::endl;
  boost::shared_ptr<A> bptr_myA(new A(10.0));
  throw "Error occured in testSharedPtr";
}

//typical memory leak problem
void testSharedPtrF(){
  std::cout<<"Calling test F"<<std::endl;
  A* ptr_myA = new A(1.0);
  ptr_myA = new A(2.0);
  delete ptr_myA;
}

//Avoiding memory leaks by shared_ptr
void testSharedPtrG(){
  std::cout<<"Calling test G"<<std::endl;
  boost::shared_ptr<A> bptr_myA(new A(20.0));
  bptr_myA.reset(new A(40.0));
  //We can also do bptr_myA = bptr_myB
}

int main()
{

  testSharedPtrA();
  //testSharedPtrB();
  testSharedPtrC();
  testSharedPtrD();
  //testSharedPtrE();
  testSharedPtrF();
  testSharedPtrG();

  return 0;
}

#endif
