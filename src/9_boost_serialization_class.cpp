//Serializing a whole class

#include<boost/function.hpp>
#include<boost/serialization/shared_ptr.hpp>
#include<boost/serialization/vector.hpp>
#include<boost/foreach.hpp>
#include<boost/random.hpp>
#include<boost/bind.hpp>
#include<fstream>
#include<ostream>
#include<sstream>
#include<boost/archive/text_oarchive.hpp>
#include<boost/archive/binary_oarchive.hpp>

#include<boost/archive/text_iarchive.hpp>
#include<boost/archive/binary_iarchive.hpp>

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

double gdmpath(double spot, double rd, double rf, double vol, double tau, double rn){
  double res = spot * std::exp((rd-rf-0.5*vol*vol)*tau+vol*std::sqrt(tau)*rn);
  return res;
}

double discountedCallpayoff(double assetvalue, double strike, double rd, double tau){
  double res = std::max(assetvalue - strike, 0.0)*std::exp(-rd*tau);
  return res;
}

double discountedPutPayoff(double assetvalue, double strike, double rd, double tau){
  double res = std::max(strike - assetvalue, 0.0)* std::exp(-rd*tau);
  return res;
}

void testingSerialization1(){
  unsigned long numSims = 1000000, seed = 20424;
  double spot = 100.0, strike = 102.0, rd = 0.02, rf = 0.03, vol = 0.124, tau = 1.0;

  boost::function<double (double)> pathGen, discountedPayoff;
  pathGen = boost::bind(gdmpath, spot, rd, rf, vol, tau, _1);
  discountedPayoff = boost::bind(discountedCallpayoff, _1, strike, rd, tau);
  SimpleGenericMonteCarloClass mc(numSims, seed);


  mc.performsimulation(pathGen, discountedPayoff);
  std::string filenameTxt("/home/abhi/advancedC/monteCarloTest.txt");
  std::string filenameBin("/home/abhi/advancedC/monteCarloTest.bin");

  std::ofstream ostrTxt(filenameTxt.c_str());
  std::ofstream ostrBin(filenameBin.c_str(), std::ios::binary);

  boost::archive::text_oarchive oaTxt(ostrTxt);
  boost::archive::binary_oarchive oaBin(ostrBin);

  oaTxt<<mc; oaBin<<mc;
  ostrTxt.close();
  ostrBin.close();

}

void testingSerialization2(){
  std::string filenameBin("/home/abhi/advancedC/monteCarloTest.bin");
  std::ifstream istrBin(filenameBin.c_str(), std::ios::binary);
  boost::archive::binary_iarchive iaBin(istrBin);
  SimpleGenericMonteCarloClass mc;
  iaBin>>mc;
  istrBin.close();
  std::cout<<"Mean old (call): "<<mc.getMean()<<std::endl;
  double spot = 100.0, strike =102.0, rd = 0.02, tau = 1.0, rf = 0.03, vol =0.124;
  boost::function<double (double)> discountedpayoff, pathGen;

  discountedpayoff = boost::bind(discountedPutPayoff, _1, strike, rd, tau);
  pathGen = boost::bind(gdmpath, spot, rd, rd, vol, tau, _1);

  mc.performsimulation(pathGen, discountedpayoff);
  std::cout<<"Mean New (put):"<<mc.getMean()<<std::endl;
}

int main(){
  testingSerialization1();
  testingSerialization2();
  return 0;
}
