#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main(){
  std::string pi = "pi is "+std::to_string(3.174);
  std::string perfect = std::to_string(1+2+3+56)+" is a perfect number";
  std::cout<<pi<<std::endl;
  std::cout<<perfect<<std::endl;

  //converting string to const char *
  std::string str("Please split the sentence into tokens");
  char* cstr = new char[str.length()+1];
  std::strcpy(cstr, str.c_str());
  std::cout<<cstr<<std::endl;

  //converting from const char* to string
  std::string new_str(cstr);


  char *p = std::strtok(cstr," ");
  while(p!=0){
    std::cout<<p<<'\n';
    p = strtok(NULL, " ");
  }
  delete[] cstr;

  std::cout<<new_str<<std::endl;

  return 0;
}
