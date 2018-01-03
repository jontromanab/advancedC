#include<iostream>
#include<future>

using namespace std;

std::mutex mu;
std::condition_variable cond;

//we want to return the result from the child thread to parent thread
// From parent thread to child thread
//void factorial(int N)
//void factorial(int N, int& x)
//int factorial(int N)
int factorial(std::future<int>& f)
{
  int res = 1;

  int N = f.get();

  for(int i=N;i>1;i--)
      res *=i;
  cout<<"Result is: "<<res<<endl;
  //x =res;
}

int main()
{
  //we can do it by std::ref
  int x;
  //std::thread t1(factorial, 4, std::ref(x));

  std::promise<int> p; //promising that we will send a value to child thread in future(which will currently not have)
  std::future<int> f = p.get_future(); //passing from main thread to child. child will accept a future

  //We can also do shared_future, which can be copied. The function will take shared_future instead of only futute


  //std::future<int> fu = std::async(factorial,4); //for getting something in future . //Creating a new thread
  std::future<int> fu = std::async(std::launch::async,factorial,std::ref(f));
  //std::future<int> fu = std::async(std::launch::deferred, factorial,4);//Not creating a new thread
  //x = fu.get(); //can be called only once. If we call it again, the program will crash

  //std::thread t1(factorial, 4);

  //t1.join();

  //do something
  std::this_thread::sleep_for(chrono::milliseconds(20));
  p.set_value(4);
  x = fu.get();

  return 0;
}


//If I dont send a value.aka not keep my promise, it will create exception of broken_promise
//we can set
//p.set_exception(std::make_exception_ptr(std::runtime_error("human error"));
