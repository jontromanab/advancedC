//Serializing a whole class

#include<boost/function.hpp>
#include<boost/serialization/shared_ptr.hpp>
#include<boost/serialization/vector.hpp>
#include<boost/foreach.hpp>
#include<boost/random.hpp>

class SimpleGenericMonteCarloClass{
private:
  boost::shared_ptr<std::vector<double> >normVec_;
  double mean_;
  unsigned long numSims_,  seed_;
  //setting up normal vec
  void constructNormalvec(){
    boost::mt19937 rng(seed_);
    boost::normal_distribution<> norm;
    boost::variate_generator<boost::mt19937&, boost::normal_distribution<> > normGen(rng, norm);
    BOOST_FOREACH(double& x, *normVec_) x = normGen();
  }

public:
  SimpleGenericMonteCarloClass(){};
  SimpleGenericMonteCarloClass(unsigned long numSims, unsigned long seed): mean_(0.0),
    numSims_(numSims),seed_(seed), normVec_(new std::vector<double>(numSims)){
    constructNormalvec();
  };
  double getMean() const{return mean_;};
  double getNumbersimulations() const{return numSims_;};
  void performsimulation(boost::function<double (double)> pathGen, boost::function<double (double)>discountedPayoff){
    mean_ = 0.0;
    double pathVal;
    BOOST_FOREACH(double x, *normVec_){
      pathVal = pathGen(x);
      mean_+=discountedPayoff(pathVal);
    }
    mean_ = mean_/((double)numSims_);
  }

  template<class Archive> void serialize(Archive & ar, const unsigned int version){
    ar& mean_;
    ar & numSims_;
  }
};

int main(){
  return 0;
}
