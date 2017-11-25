#include<vector>
#include<iostream>
#include<boost/current_function.hpp>
#include<boost/foreach.hpp>
#include<boost/static_assert.hpp>
#include<boost/detail/lightweight_test.hpp>

#define MY_NUM 1300

//Returns current function name
void testMacroA(){
  std::cout<<"You have called: "<<BOOST_CURRENT_FUNCTION<<std::endl;
}

// generates a compile time error message, If the input expression is false. If it is 1300, then there will be error
void testMacroB(){
  BOOST_STATIC_ASSERT(MY_NUM!=1400);
}

//iteration by boost. first iteration writes, and second iteration reads
void testMacroC(){
  std::vector<double> myVec(10);
  BOOST_FOREACH(double& x, myVec) x =10.0;
  BOOST_FOREACH(double x, myVec) std::cout<<x<<std::endl;
}


//part of lightweight test header. boost_error prints an error message with the name and location of error
// boost_test tests if supplied condition is true and prints and error otherwise
void testMacroD(){
  BOOST_ERROR("Failure of this function");
  double x = 0.0;
  BOOST_TEST(x!=0);
}

int main()
{
  testMacroA();
  testMacroB();
  testMacroC();
  testMacroD();
  return 0;
}
