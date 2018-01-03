#include<iostream>
#include<thread>
#include <mutex>
#include <fstream>


using namespace std;

std::mutex mu;

/*void shared_print(string msg, int id)
{
  //Not recommended to lock and unlock directly
  //mu.lock(); //lock the mutex, so while printing other threads cannot print the msg
  std::lock_guard<std::mutex> guard(mu); //RAII technique. will always be unlocked with or
  //without exception
  cout<<msg<<id<<endl; //if this line throws exception, then our mutex will locked forever
  //mu.unlock();
}*/

class LogFile{
  std::mutex m_mutex;
  std::mutex m_mutex2;
  ofstream f;
public:
  LogFile(){
    f.open("log.txt");
  }//need destructor to close file
  void shared_print(string id, int value)
  {
    std::lock(m_mutex, m_mutex2);
    std::lock_guard<std::mutex> locker(m_mutex, std::adopt_lock);
    std::lock_guard<std::mutex> locker2(m_mutex2, std::adopt_lock);
    cout<<" From "<<id<<": "<<value<<endl;
  }
  void shared_print2(string id, int value)
  {
    //std::lock_guard<std::mutex> locker2(m_mutex2);
    //std::lock_guard<std::mutex> locker(m_mutex); //will create deadlock
    //make sure locking are in same order
    /*std::lock(m_mutex, m_mutex2);
    std::lock_guard<std::mutex> locker(m_mutex, std::adopt_lock);
    std::lock_guard<std::mutex> locker2(m_mutex2, std::adopt_lock);
    cout<<" From "<<id<<": "<<value<<endl;*/
    {
    std::lock_guard<mutex> locker(m_mutex);
    }
    {
      std::lock_guard<mutex> locker2(m_mutex2);
      cout<<"From "<<id<<": "<<value<<endl;
    }
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

  for(int i=0;i<100;i++)
   log.shared_print2(string("From main: "), i);
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
