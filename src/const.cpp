/*
const
A complie time constraint that an object can not be modified

Why use const
  a.) Guard againts inadvertment write to the variable.
  b.) Self documenting
  c.) Enable compiler to do more optimization, making code tighter
  d.) const means the variable can be put in ROM
*/

#include<iostream>

int main(){

  //We cannot change const
  const int i=9;
  int j = 6;

  //data is const, pointer is not
  const int *p1 = &i; //data is const, pointer is not const
  //*p1 = 5; //This is also not possible
  p1++; //This is possible


  int* const p2 = &j ; //pointer is const, data is not const

  const int* const p3 = &i; //data and pointer are both const

  int const *p4 = &i;

  // If const is on the left of *, data is const
  // If const is on the right of *, pointer is const

  //We cannot do this
  // i = 6
  const_cast<int&>(i) = 6; //If we have to change. cast away const

  int k;
  static_cast<const int&>(k); //making k a const. Casting k to const
  //k = 7; // it is not possible now

  //ALWAYS TRY TO AVOID THIS TYPE OF CASTING


  return 0;
}
