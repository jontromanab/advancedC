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
  ofstream f;
public:
  LogFile(){
    f.open("log.txt");
  }//need destructor to close file
  void shared_print(string id, int value)
  {
    std::lock_guard<std::mutex> locker(m_mutex);
    f<<" From "<<id<<": "<<value<<endl;
  }
  //Never return f to outside world
  //ofstream& getstream() {return f;}
  //Never pass f as an argument to user provided function
  /*void processf(void fun(ofstream&)){
    fun(f);
  }*/
};


class stack{
  int* _data;
  std::mutex _mu;
public:
  void pop(); //pops item on top
  int& top(); //returns the item on top
  //..
};

/*void function_2(stack& st)
{
  int v = st.top();
  st.pop();
  process(v);
}*/

void function_1(LogFile& log)
{
  for(int i=0;i>-100;i--)
    log.shared_print(string("From t1: "), i);
}

//A race condition is a condition where the outcome of a program depends on the relative
// exclusive order of one or more threads
// NOT GOOD FOR PROGRAM
// use mutex

int main()
{
  LogFile log;
  std::thread t1(function_1, std::ref(log));

  for(int i=0;i<100;i++)
   log.shared_print(string("From main: "), i);
 t1.join();

  return 0;
}


/*
 Avoiding data race:
 1. Use Mutex to synchronize data access;
 2. Never leak a handle of data to outside
 3. Design interface appropriately
*/
