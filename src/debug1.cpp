#include<iostream>
#include<math.h>
using namespace std;

bool getRoots(const int& a, const int& b, const int& c, double& root1, double& root2){
  try{
    if(a==0)
      throw 1;
    double f = b^2 - 4*a*c;
    if (f<0)
      throw "negF";
    root1 = (-b+sqrt(f))/2*a;
    root2 = (-b-sqrt(f))/2*a;
  }



  catch(int x){
    cout<<"You cannt give a = 0;"<<endl;
  }
  catch(const char* msg){
    cout<<msg<<endl;
  }

}


int main(){
  int a = 1;
  int b = 2;
  int c = 2;
  string s ="Abhijit";
  double r1, r2;
  getRoots(a,b,c,r1,r2);
  cout<<"The roots are: "<<r1<<" and "<<r2<<endl;
  return 0;
}
