// Making threads and using lambdas

#include<iostream>
#include<thread>

using namespace std;


void threadFn(int& value, int val2){
  std::cout<<"I am from thread"<<std::endl;
  std::cout<<"My value is : "<<value++<<std::endl;
  std::cout<<"thread function ID: "<<this_thread::get_id()<<std::endl;
  std::cout<<"Second value is: "<<val2<<std::endl;
}

int main(){
  int localValue = 150;
  thread t1{threadFn, ref(localValue),100};
/*
  thread t1{[](int& value){
      std::cout<<"I am from thread"<<std::endl;
      std::cout<<"My value is : "<<value++<<std::endl;
    },ref(localValue)};
*/

/*
  thread t1{[&](){
      std::cout<<"I am from thread"<<std::endl;
      std::cout<<"My value is : "<<localValue++<<std::endl;
    }};

*/
  t1.join();
  std::cout<<"I am from main"<<std::endl;
  std::cout<<"Main thread ID: "<<this_thread::get_id()<<std::endl;
  std::cout<<"Value in main: "<<localValue<<std::endl;
  return 0;
}
