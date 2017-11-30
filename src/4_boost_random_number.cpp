/*
General construction procedure for random number generator
1. Set a seed such that we can reproduce the same number
2. choose a random series generator such as Mersenne-Twister
3. choose the distribution function
4. connect the random series generator and distribution function via a variate generator
5. generate random number

The following random number generators are available
- Linear Congruential
- Addictive Combine
- Inverse Congruential
- Shuffle Output
- Mersenne Twister with a period length of 2^19937
- Various lagged Fibonacci generators

The following distributiosn have a random number generator
uniform_int: Uniform on a set of integers
uniform_real: Continuous uniform
uniform_sphere: Uniform on a unit sphere
triangle_distribution
bernoulli_distribution
exponential_distribution
poisson_distribution
geometric_distribution
cauchy_distribution
normal_distribution
lognormal_distribution
*/

#include<iostream>
#include<boost/random.hpp>


//generate discrete uniform random numbers in the set {1....6} with Mersenne-Twister
void randomFunc1(){
  //create seed
  unsigned long seed = 12411;
  //produces general pseudo random number series with the Mersenne Twister algo
  boost::mt19937 rng(seed);
  //uniform distribution in 1....6
  boost::uniform_int<> six(1,6);
  //connects distribution with random series
  boost::variate_generator<boost::mt19937&, boost::uniform_int<> > unsix(rng, six);

  std::cout<<unsix()<<std::endl;
  std::cout<<unsix()<<std::endl;
  std::cout<<unsix()<<std::endl;
}

////generate random number by Fibonacci generator
void randomFunc2(){
  //create seed
  unsigned long seed = 89210;
  //produces general pseudo random number series with lagged fibonacci algo
  boost::lagged_fibonacci1279 rng(seed);
  //normal distribution with mean 10 and st deviation 0.1
  boost::normal_distribution<> norm(10,0.1);
  //connects distribution with random series
  boost::variate_generator<boost::lagged_fibonacci1279&, boost::normal_distribution<> > unnorm(rng, norm);
  std::cout<<unnorm()<<std::endl;
  std::cout<<unnorm()<<std::endl;
  std::cout<<unnorm()<<std::endl;
}


int main(){

  randomFunc1();
  randomFunc2();
  return 0;
}
