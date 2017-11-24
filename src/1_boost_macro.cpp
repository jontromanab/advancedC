#include<vector>
#include<iostream>
#include<boost/current_function.hpp>
#include<boost/foreach.hpp>
#include<boost/static_assert.hpp>
#include<boost/detail/lightweight_test.hpp>

#define MY_NUM 1300

void testMacros(){
  std::cout<<"You have called: "<<BOOST_CURRENT_FUNCTION<<std::endl;
}

int main()
{
  testMacros();
  return 0;
}
