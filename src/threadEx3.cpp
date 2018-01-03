//USing future and promise
//async programming
//promise: container of future
// launches asynchronously: launch thread separate from main


//we can call multiple times the factorial thread, by using shared_future

#include<iostream>
#include<thread>
#include<future>

using namespace std;

/*
void threadFn(){
  cout<<"I am from thread"<<endl;
}*/

int asyncFn(){
  cout<<"Async thread id: "<<this_thread::get_id()<<endl;
  cout<<"I am from async function"<<endl;
  return 100;
}

int asyncFn2(int val){
  return val+100;
}

//By sending a promise, I am telling that I will be sendind a value, but I dont have it right now
void threadFn(promise<int>& prom){
  this_thread::sleep_for(chrono::milliseconds(1000));
  prom.set_value(200);
}

int factorial(std::future<int>& f){
  int res = 1;
  int N = f.get();
  for(int i=N;i>1;i--)
    res *=i;
  cout<<"Result is: "<<res<<endl;
  return res;
}

int main(){
  //thread t1{threadFn};
  //t1.join();
  cout<<"main thread: "<<this_thread::get_id()<<endl;
  future<int> fn = async(launch::async, asyncFn);
  cout<<"async returns: "<<fn.get()<<endl;

  //now the function will be called when we call get(). The thread id will be same with the main thread
  future<int> fn2 = async(launch::deferred, asyncFn);
  cout<<"async returns: "<<fn2.get()<<endl;
  //fn2.get(); //we cannot call get again. from async we can call only once

  //sending value
  future<int> fn3 = async(launch::async, asyncFn2, 300);
  cout<<"async2 returns: "<<fn3.get()<<endl;

  if(fn3.valid())
    cout<<"calling get: "<<fn3.get()<<endl;
  else
    cout<<"Invalid: "<<endl;



  //Promise
  promise<int> myPromise;
  future<int> fut = myPromise.get_future();
  myPromise.set_value(100);
  cout<<"From future promise: "<<fut.get()<<endl;

  //sending promise
  promise<int> myPromise2;
  future<int> fut2 = myPromise2.get_future();
  thread t1{threadFn, ref(myPromise2)};
  cout<<"Main thread "<<fut2.get()<<endl;
  t1.join();


  //sending future
  int x;
  promise<int> p;
  future<int> f = p.get_future();
  //std::future<int> fu = async(launch::async, factorial, std::ref(f));
  auto fu = async(launch::async, factorial, std::ref(f));
  //do somethin else
  std::this_thread::sleep_for(chrono::milliseconds(1000));
  p.set_value(4);


  x = fu.get();
  cout<<"Get from child: "<<x<<endl;
  return 0;
}
