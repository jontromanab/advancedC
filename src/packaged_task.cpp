#include<iostream>
#include<thread>
#include <mutex>
#include <fstream>
#include <future>
#include<deque>


using namespace std;


int factorial(int N){
  int res = 1;
  for(int i=N;i>1;i--)
    res  *=i;
  cout<<"Result is: "<<res<<endl;
  return res;
}

std::deque<std::packaged_task<int()> > task_q;
std::mutex mu;
std::condition_variable cond;

void thread_1()
{
  std::packaged_task<int()> t;
  {
    std::unique_lock<std::mutex> locker(mu);
    cond.wait(locker, [](){return !task_q.empty();});
    std::move(task_q.front());
    task_q.pop_front();
  }
  t();
}


//packaged_task can link a callable object to a future

int main(){
  //std::thread t1(factorial, 6);
  //std::packaged_task<int(int)> t(factorial); to call with t(6)
   //t(6); //In a different context

  //std::packaged_task<int()> t(std::bind(factorial,6));
  //t();

  //int x = t.get_future().get();
  //std::cout<<"x is: "<<x<<endl;

  std::thread t1(thread_1);
  std::packaged_task<int()> t(std::bind(factorial,6));
  std::future<int> fu = t.get_future();
  {
    std::lock_guard<std::mutex> locker(mu);
    task_q.push_back(std::move(t));
  }
  cond.notify_one();
  cout<<fu.get();

  t1.join();
  return 0;
}
