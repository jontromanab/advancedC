#include <iostream>
#include <thread>
using namespace std;

void function_1()
{
  cout<<"Beauty is only skin-deep "<<endl;
}

class Fctor{
public:
  void operator()(string& msg){
   for(int i=0;i>-100;i--)
     cout<<"from t1 "<<i<<endl;
    cout<<" t1 says: "<<msg<<endl;
    msg = "Thrust is the mother of deceit";
    cout<<"Child thread id: "<<std::this_thread::get_id()<<endl;
  }
};


int main()
{
  Fctor fct;
  //std::thread t1(fct);
  //std::thread t1((Fctor())); //passing without argument and directly initializing the class in thread object

  string s = "Where there is no trust, there is no love";
  cout<<"Main thread id: "<<std::this_thread::get_id()<<endl; //parent thread id
  //std::thread t1((Fctor()), s); //passing with argument
  std::thread t1((Fctor()),std::ref(s)); //passing argument by ref
  //PARAMETER TO A THREAD ALWAYS PASSED BY VALUE

  //std::thread t1((Fctor()), std::move(s)); //passing by Move. Moves s from main thread to child thread

  // Thread cannot be copied. so we cannot make std::thread t2 = t1;
  // But we can change ownership by move function std::thread t2 = std::move(t1);
  std::thread t2 = std::move(t1);

  //Print child thread id
  cout<<t2.get_id()<<endl;

  //std::thread t1(function_1); //t1 starts running
  //What about a thread neither joined nor detached. If t1 destroyed before thread can join or detach, then program will terminate
  // We have to make a decision for t1 if it joins to detaches before t1 goes out of scope

  //before joining we have to do something
  //parent thread
  //using try throw
  /*try
  {
     //for(int i=0;i<100;i++)
      //cout<<" from main: "<<i<<endl;
    cout<<" from main: "<<s<<endl;
  }catch(...){
    t1.join();
    throw;
  }*/

  t2.join();
  cout<<"main says: "<<s<<endl;

  //using RAII
  // Wrapper w(t1); //In the destructor of the wrapper class we will call t1.join();

  //Dont get into oversubscription. Creating more threads than we can handle
  //std::thread::hardware_concurrency();//Indicates how many threads can be run
  std::cout<<"hardware concurrency: "<< std::thread::hardware_concurrency()<<endl;


  //IF we want to join
  //t1.join();
  return 0;
}
