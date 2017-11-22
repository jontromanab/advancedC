#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

 //basic lambda function
 auto sayHello = [](){cout<<"nope"<<endl;};
 sayHello();

 //lambda function with parameters
 auto sayHelloP = [](int a, int b){return a+b;};
 cout<<"SayHello says: "<<sayHelloP(190, 10)<<endl;

 //lambda function with parameters optional argument
 auto product =[](int x, int y) -> int //it is something like a function pointer
 {
   return x*y;
 };
 cout<<"Product is: "<<product(7,10)<<endl;
 return 0;
}
