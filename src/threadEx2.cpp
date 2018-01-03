//Using template and STL

#include<iostream>
#include<thread>
#include<initializer_list>

template<typename T>
void threadFn(){
  std::cout<<"I am from thread"<<std::endl;
  std::cout<<"Type is =>"<<typeid(T).name()<<std::endl;
}

void threadFn2(std::initializer_list<int> i1){
  std::cout<<"Size of initializer list: "<<i1.size()<<std::endl;
}


int main(){
  /*std::thread t1{threadFn<int>};
  std::this_thread::sleep_for(std::chrono::microseconds(1000));
  std::thread t2{threadFn<float>};
  t1.join();
  t2.join();*/
  std::initializer_list<int> i1 = {1,2,3,4,5};
  std::thread t3{threadFn2, i1};
  t3.join();

  return 0;
}
