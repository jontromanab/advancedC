#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
using namespace std;

//Creating thread
/*
void func(int x){
  cout<<"Inside thread "<<x<<endl;
}

int main(){
  thread th(&func, 100);
  th.join();
  cout<<"Outside thread "<<endl;
  return 0;
}
*/

/*
//Race conditions
int accum = 0;
void square(int x){
  int temp = accum;
  temp +=x*x;
  accum = temp;
}

int main(){
  vector<thread> ths;
  for(int i=1;i<=20;i++){
    ths.push_back(thread(&square, i));
  }

  for (auto& th: ths){
    th.join();
  }

  cout<<"accum = "<<accum<<endl;
  return 0;
}

//The answer should be 2870. But couple of times it will be incorrect. This is a race condition.
// As accum is a global variable. We can also send accum as a ref. thread(&square, ref(accum), i). Or we can use mutex

*/


int accum = 0;
mutex accum_mutex;

void square(int x){
  int temp = x *x;

  accum_mutex.lock();
  std::cout<<"x = "<<x<<std::endl;
  cout<<"id: "<<this_thread::get_id()<<endl;
  accum +=temp;
  accum_mutex.unlock();
}

int main(){
  std::vector<thread> ths;
  for(int i=1;i<=20;++i)
    ths.push_back(thread(&square, i));
  for(auto& th: ths) th.join();
  cout<<"accum = "<<accum<<endl;
  return 0;
}
// It is important to introduce the variable temp, since we want the x*x calculations to be
// outside the lock-unlock block, otherwise we would be hogging the lock while running calculations

