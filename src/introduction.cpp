/*
MultiThreading:
Pro:
1. Fast to start
2. Low overhead

Cons:
1. Difficult to implement
2. Can't run on distrinuted systems

*/

#include <iostream>
#include <thread>
using namespace std;

void function_1()
{
  cout<<"Beauty is only skin-deep"<<endl;
}

int main()
{
  std::thread t1(function_1); //t1 starts running
  //t1.join(); //main thread waits for t1 to finish

  //t1.detach(); // t1 will run freely on its own-- its now a daemon process
  //t1 did not get the chance to print. Because main thread ran so fast
  //Each thread is running independtently. So the threading is nondetermininstic which thread will come first
  //That's why need synchronization

  //t1.join(); //We cannot do that now. once detached forever detached
  //we can check if it is joinable
  if(t1.joinable())
    t1.join(); //Program is not crashing now

  //function_1();
  return 0;
}
