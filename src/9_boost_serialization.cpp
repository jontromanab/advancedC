/*
The serialization library allows to store classes and objects in binary format. The original objects can be later
reconstructed from the binary files. The binary format can be a text file, xml file or bin file. The library allows
to incorporate serialization for some standard STL objects.

Let's assume we want to generate 5.000.000 normal random variable once, store them in a std::vector and
reuse it in other classes later. This will save time as we dont have to generate the numbers again. We will
store the bin file which is in this case smaller than an equivalent text file. To do this, we initilize the
standard interface to write data to files as output streams by creating a std::ofstream object with the
std::ios::binary flag.

std::ofstream ostr("filepath", std::ios::binary)

as we are interested in bin serialization, we will include

<boost/archieve/binary)oarchive.hpp>
*/

#include<boost/archive/binary_oarchive.hpp>
#include<boost/serialization/vector.hpp>
#include<boost/foreach.hpp>
#include<boost/random.hpp>
#include<fstream>
#include<ostream>
#include<sstream>
#include<boost/timer.hpp>


void testingSerialization1(){
  //start timer
  boost::timer t;
  //random number generator setup
  unsigned long seed = 89210;
  std::stringstream stream; stream<<seed;
  //create an open an achive for output
  std::string filename("/home/abhi/advancedC/");
  filename+="normal_nt_"+stream.str()+".bin";
  //
  std::ofstream ostr(filename.c_str(), std::ios::binary);
  boost::archive::binary_oarchive oa(ostr);
  //setup random number generators
  boost::mt19937 rng(seed);
  boost::normal_distribution<> norm;
  boost::variate_generator<boost::mt19937&, boost::normal_distribution<>> normGen(rng, norm);
  //
  int numVars = 5000000;
  std::vector<double> myVec(numVars);
  BOOST_FOREACH(double& x, myVec) x = normGen();
  //serialize myVec
  oa<<myVec;
  //close file
  ostr.close();
  std::cout<<"Elapsed time: "<<t.elapsed()<<std::endl;
}


int main(){
  testingSerialization1();
  return 0;
}
