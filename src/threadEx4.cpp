/*
mutex:

lock_guard: RAII: so we dont have to manually unlock it
unique_lock: we can lock and unlock it multiple timespec
*/

#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

void threadFn(mutex& mtx){
  lock_guard<mutex> lock(mtx);
  cout<<"I locked the mutex"<<endl;
  this_thread::sleep_for(chrono::seconds(2));

}


int main(){
  mutex mx;
  thread th{threadFn,ref(mx)};
  this_thread::sleep_for(chrono::seconds(1));
  unique_lock<mutex> lock(mx);
  cout<<"I am inside the main thread"<<endl;


  th.join();
  return 0;
}
