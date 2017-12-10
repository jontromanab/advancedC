/*
compiler silently writes 4 functions if they are not explicitly declared:
1. Copy constructor
2. Copy Assignmnet Operator
3. Destructor
4. Default Constructor


For disallowing functions
1. c++11: f() = delete
2. c++ 03: Declare the functions to be private, and not define it
3. Private destructor: stay out of stack
*/

#include<iostream>

using namespace std;

class OpenFile{
public:
  OpenFile(string filename){
    cout<<"Open a File: "<<filename<<endl;
  }
  //OpenFile(OpenFile& rhs) = delete; //For c++11
  void g(OpenFile& f){OpenFile f2(f);}
  void destroyMe() {delete this;}
private:
  OpenFile(OpenFile& rhs);
  OpenFile& operator =(const OpenFile& rhs);
  void writeLine(string str);
  //~OpenFile(){cout<<"OpenFile Destructed: "<<endl;}

};

int main(){
  OpenFile f(string("bo_file"));
  //OpenFile f2(f);
  //f.destroyMe();
  OpenFile* f1 = new OpenFile(string("bo_file"));
  f1->destroyMe();
  return 0;

}
