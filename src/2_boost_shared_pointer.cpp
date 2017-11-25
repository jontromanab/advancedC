#ifndef TEST_CLASS_A
#define TEST_CLASS_A

#include<iostream>

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
  A* ptr_myA = new A(1.0);
  delete ptr_myA;
}


int main()
{

  testSharedPtrA();

  return 0;
}

#endif
