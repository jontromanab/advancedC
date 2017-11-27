/*Ther are several kind of distribtions present in Boost

1. Bernoulli Distribution
2. Beta Distribution
3. Binomial Distribution
4. Cauchy-Lorentz Distribution
5. Chi Squared Distribution
6. Exponential Distribution
7. Extreme Value Distribution
8. F Distribution
9. Gamma and Erlang Distribution
10. Log Normal Distribution
11. Negative Binomial Distribution
12. Noncentral Beta Distribution
13. Noncetral Chi-Squared Distribution
14. Noncentral F Distribution
15. Noncentral T Distribution
16. Nornal (gaussian) Distribution
17. Pareto Distribution
18. Poisson Distribution
19. Rayleigh Distribution
20. Students T Distribution
21. Triangular Distribution
22. Weibull Distribution
23. Uniform Distribution

On each distribution, we can apply the usual operations, such as calculation of the
cumulative distribution value at a given point x. The following operations are available with
corresponding syntax

cumulative distribution function: cdf(distribution,x)
density: pdf(distribution,x)
inverse CDF: quantile(distribution,x)
complementary CDF: cdf(complement(distribution,x))
Mean: mode(distribution)
variance: variance(distribution)
st. deviation: standard_deviation(distribution)
skew: skewness(distribution)
kurtosis: kurtosis(distribution)
excess kurtosis: kurtosis_excess(distribution)

*/

#include <iostream>
#include <boost/math/distributions.hpp>

void distributionFn(){
  boost::math::normal_distribution<> d(0.5,1);

  std::cout<<"CDF: "<<cdf(d, 0.2)<<std::endl;
  std::cout<<"PDF: "<<pdf(d, 0.0)<<std::endl;
  std::cout<<"Inverse: "<<quantile(d, 0.1)<<std::endl;
  std::cout<<"Mode: "<<mode(d)<<std::endl;
  std::cout<<"Variance: "<<variance(d)<<std::endl;
  std::cout<<"SD: "<<standard_deviation(d)<<std::endl;
  std::cout<<"Skew: "<<skewness(d)<<std::endl;
  std::cout<<"Kurtosis: "<<kurtosis(d)<<std::endl;
  std::cout<<"Excess Kurt: "<<kurtosis_excess(d)<<std::endl;

  std::pair<double, double> sup = support(d);
  std::cout<<"Left sup: "<<sup.first<<std::endl;
  std::cout<<"Right sup: "<<sup.second<<std::endl;
}

int main(){
  distributionFn();
  return 0;
}


