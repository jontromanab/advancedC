#include<iostream>
#include<vector>
using namespace std;

int main()
{
  //XOR of two numbers
  cout<<"2^3: "<<(2^3)<<endl;
  cout<<"2^2: "<<(2^2)<<endl;
  cout<<"2^3^2: "<<(2^3^2)<<endl;

  //Find the number which occurs odd number of times
  vector<int> v = {1,5,5,1,2,3,4,2,1,2,1,2,3,2};
  int odd_n = 1;
  for(int i=0;i<v.size();i++)
  {
    odd_n = odd_n^v[i]^odd_n;
  }
  cout<<"Odd occurances for number: "<<odd_n<<endl;
  odd_n = 0;

  for(vector<int>::iterator it=v.begin();it!=v.end();it++)
  {
    odd_n = odd_n^(*it)^odd_n;
  }
  cout<<"Odd occurances for number: "<<odd_n<<endl;

  //Find missing number in an array
  vector<int> v2 = {1,2,3,5,6,7,8};
  int sum_of_range = 0;
  int sum_of_numbers = 0;
  for(auto i: v2)
  {
    sum_of_numbers+=i;
  }
  cout<<"Sum of numbers: "<<sum_of_numbers<<endl;

  sum_of_range = v2[v2.size()-1];
  sum_of_range = sum_of_range* (sum_of_range+1)/2;
  cout<<"Sum of range: "<<sum_of_range<<endl;
  cout<<"Missing number: "<<sum_of_range-sum_of_numbers<<endl;

  return 0;
}
