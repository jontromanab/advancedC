/*
 using condition variable
 signalling between threads

*/
#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>

using namespace std;

bool var = true;

void threadFn(mutex& mtx, condition_variable& convar){
  unique_lock<mutex> lock(mtx);
  convar.wait(lock);

  cout<<"End of thread"<<endl;
}

int main(){
  mutex mx;
  condition_variable convar;
  thread th(threadFn, ref(mx), ref(convar));
  this_thread::sleep_for(chrono::seconds(2));

  convar.notify_all();

  th.join();
  std::cout<<"I am in main"<<endl;
  return 0;
}
