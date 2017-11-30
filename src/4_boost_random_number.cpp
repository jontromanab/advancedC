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
