#include<boost/serialization/vector.hpp>
#include<fstream>
#include<ostream>
#include<sstream>
#include<boost/timer.hpp>
#include<boost/archive/binary_iarchive.hpp>

void testingSerialization2(){
  boost::timer t;
  //create and open a character archive for input
  std::string filename("/home/abhi/advancedD/");
  filename+= "normal_nt_89210.bin";

  std::ifstream istr(filename.c_str(), std::ios::binary);
  std::vector<double> myVecLoaded;
  //create and open an archive for input
  boost::archive::binary_iarchive ia(istr);
  ia>>myVecLoaded;
  istr.close();

  for(int i=0;i<10;i++) std::cout<<myVecLoaded[i]<<std::endl;
  std::cout<<"-----------------------------------"<<std::endl;
  std::cout<<"Elapsed: "<<t.elapsed()<<std::endl;
}


int main(){
  testingSerialization2();
  return 0;
}
