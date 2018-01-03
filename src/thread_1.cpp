#include<iostream>
#include<thread>

void threadFunc(){
  std::cout<<"Hello from thread! \n"<<std::endl;
}

int main(){
  std::thread th(threadFunc);
  th.join();
  std::cout<<"Hello from main! \n"<<std::endl;
  return 0;
}
