/***
 * We are starting with a simplistic program of adding a vector of ints.
 * It will add the components from left to middle and middle to end in separate threads.
 * Add finally add all of them
*/

#include <iostream>
#include <vector>
#include <thread>
#include <iterator>
#include <algorithm>
#include <future>

void adder(const std::vector<int>& v, int begin, int end, int& result){
  for( ; begin<end;++begin){
    result = result + v.at(begin);
  }
}


//Set of improvements

using size_type = std::vector<int>::size_type;
/**
 * @brief correct type of index into std::vec
 */
int adder_int(const std::vector<int>& v, size_type begin, size_type end){
  int result = 0;
  for( ; begin<end;++begin){
    result = result + v.at(begin);
  }
  return result;
}

/**
 * @brief storing in different containers
 */
template <typename Iterator>
int adder_gen(Iterator begin, Iterator end){
  int result = 0;
  for(auto it = begin; it !=end; ++it){
    result += *it;
  }
  return result;
}

/**
 * @brief any kind of numeric type
 */
template <typename Iterator>
typename std::iterator_traits<Iterator>::value_type
adder_gen_numeric(Iterator begin, Iterator end){
  typename std::iterator_traits<Iterator>::value_type result;
  for(auto it = begin; it!=end;++it){
    result += *it;
  }
  return result;
}

/**
 * @brief using accumulate
 */
template<typename Iterator>
typename std::iterator_traits<Iterator>::value_type
adder_accum(Iterator begin, Iterator end){
  using T = typename std::iterator_traits<Iterator>::value_type;
  return std::accumulate(begin, end, T());
}

/**
 * @brief paralleliation using future
 */
template<typename Iterator>
typename std::iterator_traits<Iterator>::value_type
parallel_sum(Iterator begin, Iterator end){
  using T = typename std::iterator_traits<Iterator>::value_type;
  auto midpoint = begin + std::distance(begin, end)/2;
  std::future<T> f1 = std::async(std::launch::async, adder_accum<Iterator>, begin, midpoint);
  std::future<T> f2 = std::async(std::launch::async, adder_accum<Iterator>, midpoint, end);
  return f1.get() + f2.get();
}

int main(int argc, char** argv){
  int sum_left = 0;
  int sum_right = 0;
  std::vector<int> v(100,2);

  /*
  int v_size = v.size();

  std::thread t1(adder, v, 0, v_size/2, std::ref(sum_left));
  std::thread t2(adder, v, v_size/2, v_size, std::ref(sum_right));

  t1.join();
  t2.join();

  int sum_total = sum_left + sum_right;*/

  //with future
  int sum_total = parallel_sum(v.begin(), v.end());
  std::cout<<"Total is: "<<sum_total<<std::endl;
  return 0;
}
