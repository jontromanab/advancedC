#include<iostream>
#include<thread>
#include <mutex>
#include <fstream>


using namespace std;

std::mutex mu;

/*class LogFile{
  std::mutex _mu;
  ofstream _f;
public:
  LogFile(){
    _f.open("log.txt");
  }//need destructor to close file
  void shared_print(string id, int value)
  {
    //std::lock_guard<mutex> locker(_mu);
    //using unique lock
     std::unique_lock<mutex> locker(_mu);
    _f<<"From "<<id<<": "<<value<<endl;
    locker.unlock(); //for other jobs that does not need mutex
    //...


    //We can lock and unlock multiple times
    std::unique_lock<mutex> locker(_mu, std::defer_lock);
    //do something else

    //NOw lock and use the mutex
    locker.lock();
     _f<<"From "<<id<<": "<<value<<endl;
     locker.unlock();
     //..

     locker.lock();

     //moving a locker
     std::unique_lock<mutex> locker2 = std::move(locker);

  }
};*/


class LogFile{
  std::mutex _mu;
  std::once_flag _flag;
  ofstream _f;
public:
  LogFile(){
    }//need destructor to close file
  void shared_print(string id, int value)
  {
    //std::unique_lock<mutex> locker2(_mu_open);
    //if(!_f.is_open()) {//lazy initialization
      // _f.open("log.txt");
    //}
    std::call_once(_flag, [&](){_f.open("log.txt");}); //file will be opened only once
    std::unique_lock<mutex> locker(_mu, std::defer_lock);
   _f<<"From "<<id<<": "<<value<<endl;
  }
};

void function_1(LogFile& log)
{
  for(int i=0;i>-100;i--)
    log.shared_print(string("From t1: "), i);
}


int main()
{
  LogFile log;
  std::thread t1(function_1, std::ref(log));

  t1.join();

  return 0;
}

/* Avoiding deadlock
1. prefer locking single mutex at a time
2. Avoid locking a mutex and then calling a user provided function.
3. use std:;lock() to lock more than one mutex
4. lock the mutex in same order for all threads


locking granularity:
-Fine-grained lock: protects small amount of data
- Coarse-grained lock: protects big amount of data

*/
