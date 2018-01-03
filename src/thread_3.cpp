//joinable threads
//passing ref to threads

#include<iostream>
#include<thread>
#include<vector>
#include<algorithm>
#include<assert.h>

void thFunc(int & i)
{
  std::cout<<"Hi from worker "<<i<<"!\n";
}

void test(std::vector<std::thread>& workers)
{
  for(int i=0;i<10;++i)
  {
    auto th = std::thread(&thFunc, std::ref(i));
    workers.push_back(std::move(th));
    assert(!th.joinable());
  }
}

int main(){
  std::vector<std::thread> workers;
  test(workers);
  std::cout<<"Hi from main!\n";
  std::for_each(workers.begin(), workers.end(),[](std::thread &th)
  {
    assert(th.joinable());
    th.join();
  });
  return 0;
}
