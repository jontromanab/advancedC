/*
uBLAS is a C++ version of BLAS with a STL conforming iterator interface.
dense, identity, traingular, banded, symmetric, hermitian, sparse matrices

a vector containgin double  variable is initialized via vector<double> myVec(unsigned int dim, double x)
dim is the dimension and x is defaut param

a matrix can be created via matrix<T> myMat(unsigned int rows, unsigned int cols)
access of elements myMat(row, col)
row size: matMat.size1()
col size: myMat.size2()
*/

#include<boost/numeric/ublas/vector.hpp>
#include<boost/numeric/ublas/io.hpp>

#include<boost/numeric/ublas/matrix.hpp>
#include<boost/numeric/ublas/symmetric.hpp>

#include<boost/numeric/ublas/matrix_proxy.hpp>
#include<boost/numeric/ublas/vector_proxy.hpp>


using namespace boost::numeric::ublas;

void vecOperation1(){
  vector<double> myVec(3,2.2);
  myVec[2] = -5.1;

  std::cout<<myVec<<std::endl;
  std::cout<<sum(myVec)<<std::endl;
  std::cout<<norm_1(myVec)<<std::endl; // sum of positive of v[i]
  std::cout<<norm_2(myVec)<<std::endl; // sq root of sum of v[i]^2
  std::cout<<norm_inf(myVec)<<std::endl; //max of positive of v[i]
  std::cout<<index_norm_inf(myVec)<<std::endl;
}

void vecOperation2(){
  vector<double> myVec1(3,2.2); myVec1[2] = -5.1;
  vector<double> myVec2(3, -1.2);myVec2[2] = 1.1;

  double multiplier =2.0;
  std::cout<<"-----------------------------------------"<<std::endl;
  std::cout<<myVec1.size()<<std::endl;
  std::cout<<myVec1<<std::endl;
  std::cout<<myVec2<<std::endl;
  std::cout<<inner_prod(myVec1, myVec2)<<std::endl;
  std::cout<<myVec1 + myVec2<<std::endl;
  std::cout<<myVec1 - myVec2<<std::endl;
  std::cout<<myVec1 * multiplier<<std::endl;
  std::cout<<myVec1 / multiplier<<std::endl;
}

void matrixOperation1(){
  matrix<double> mymat(3,3,2.5);
  mymat(0,0) = mymat(2,2) = 1.0;
  mymat(0,2) = -3.6; mymat(2,0) = 5.9;
  std::cout<<"-----------------------------------------"<<std::endl;
  std::cout<<"My mat: "<<mymat<<std::endl;
  std::cout<<"Num rows: "<<mymat.size1()<<std::endl;
  std::cout<<"Num cols: "<<mymat.size2()<<std::endl;
  std::cout<<"Mat transpose: "<<trans(mymat)<<std::endl;
  std::cout<<"Mat real part: "<<real(mymat)<<std::endl;
  mymat.resize(4,4);
  std::cout<<"Resized mat: "<<mymat<<std::endl;
}

void matrixOperation2(){
  //defining a symmetric correlation matrix
  symmetric_matrix<double, upper> myCorrMat(3);
  myCorrMat(0,0) = myCorrMat(1,1) = myCorrMat(2,2) = 1.0;
  myCorrMat(0,1) = 0.4; myCorrMat(0,2) = -0.6;
  myCorrMat(1,2) = 0.1;
  std::cout<<"Initial mat: "<<myCorrMat<<std::endl;

  double multiplier = 0.5;
  symmetric_matrix<double, upper> myCorrMat1 = myCorrMat;
  std::cout<<"-----------------------------------------"<<std::endl;
  std::cout<<"Sum mat: "<<myCorrMat1+myCorrMat<<std::endl;
  std::cout<<"Scalar mult: "<<myCorrMat1* multiplier<<std::endl;
  std::cout<<"Scalar Dev: "<<myCorrMat1/multiplier<<std::endl;
}

void matrixOperation3(){
  matrix<double> myMat(3,3,2.5);
  myMat(0,0) = myMat(2,2) = 1.0;
  myMat(0,2) = -3.6; myMat(2,0) = 5.9;

  matrix_row<matrix<double>> mr(myMat,2);
  matrix_column<matrix<double>> mc(myMat,2);
  std::cout<<"-----------------------------------------"<<std::endl;
  std::cout<<"mat: "<<myMat<<std::endl;
  std::cout<<"Row: "<<mr<<std::endl;
  std::cout<<"Col: "<<mc<<std::endl;
}

int main(){
  vecOperation1();
  vecOperation2();
  matrixOperation1();
  matrixOperation2();
  matrixOperation3();
  return 0;
}
