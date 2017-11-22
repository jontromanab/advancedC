#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>

using namespace std;

struct Point
{
  double x,y;
  Point() {
    x =(rand()%10000) - 5000;
    y =(rand()%10000) - 5000;
  }

  void Print(){
    cout<<"["<<x<<", "<<y<<"]";
  }
};

void PerformOperation(std::function<void ()> f){
  f();
}

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


 //we cant use outside variable in the lamda function. thats where the capture list is . The i is read only. But we can change g
 int i=10;
 int g = 20;
 auto sayHelloC = [i, &g](int a, int b){return a+b+i+g;};
 //auto sayHelloC = [=](int a, int b){return a+b+i+g;}; //For any variable we can take i, g whatever
 //auto sayHelloC = [&](int a, int b){return a+b+i+g;}; //For any variable we can take i, g whatever by reference
 //auto sayHelloC = [&, i](int a, int b){return a+b+i+g;}; //For any variable taken by reference, only i by value
 //auto sayHelloC = [=, &i](int a, int b){return a+b+i+g;}; //For any variable taken by value, only i by reference
 //cout<<"SayHelloC says: "<<sayHelloC(190, 10)<<endl;

 //with vector
 std::vector<int> arr = {1,2,3,4,5};
 double total = 0;
 std::for_each(begin(arr), end(arr),[&](int x){total +=x;});
 std::cout<<"Total is : "<<total<<endl;


 //Lambda and sorting
 int count = 100;
 vector<Point> points;
 for(int i=0;i<count;i++)
   points.push_back(Point());

 cout<<"Unsorted: "<<endl;
 for(int i=0;i<10;i++)
   points[i].Print();

 std::sort(points.begin(), points.end(),
      [](const Point& a, const Point&b)->bool{
   return(a.x*a.x)+(a.y * a.y) < (b.x*b.x)+(b.y*b.y);
 });
 cout<<endl;
 cout<<"Sorted: "<<endl;
 for(int i=0;i<10;i++)
   points[i].Print();
  cout<<endl;



 //lambdas and std::function. we have captured x
 int x =100;
 auto func = [&](){
   x++;
 };
 PerformOperation(func);
 cout<<"X: "<<x<<endl;
 return 0;
}
