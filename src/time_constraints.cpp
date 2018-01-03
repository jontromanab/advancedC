#include<iostream>
#include<thread>
#include <mutex>
#include <fstream>
#include <future>


using namespace std;

int factorial(int N){
  int res = 1;
  for(int i=N;i>1;i--)
    res  *=i;
  cout<<"Result is: "<<res<<endl;
  return res;
}

int main(){
  //thread
  std::thread t1(factorial,6);
  std::this_thread::sleep_for(chrono::microseconds(3));
  chrono::steady_clock::time_point tp = chrono::steady_clock::now() + chrono::microseconds(4);
  std::this_thread::sleep_until(tp);

  //mutex
  std::mutex mu;
  std::lock_guard<mutex> locker(mu);
  std::unique_lock<mutex> ulocker(mu);
  ulocker.try_lock();
  ulocker.try_lock_for(chrono::nanoseconds(500));
  ulocker.try_lock_until(tp);

  //condition variable
  std::condition_variable cond;
  cond.wait_for(chrono::microseconds(2));
  cond.wait_until(ulocker, tp);

  //future and promise
  std::promise<int> p;
  std::future<int> f = p.get_future();
  f.get();
  f.wait();
  f.wait_for(chrono::milliseconds(2));
  f.wait_until(tp);

  //async
  std::future<int> fu = async(factorial, 6);

  //packaged_task
  std::packaged_task<int(int)> t(factorial);
  std::future<int> fu2 = t.get_future();
  t(6);

}
