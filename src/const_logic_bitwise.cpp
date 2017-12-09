#include<iostream>
#include<vector>
class bigArray{
  std::vector<int> v;//huge vector
  mutable int accessCounter; //by changing it to mutable we can run the getITem function as const
  //mutable used for logic constness
  int* v2; //another int array

public:
  int getItem(int index) const {
    accessCounter++;
    //instead of mutable we can also do
    //const_cast<bigArray*>(this)->accessCounter++;
    return v[index];
  }

  void setV2Item(int index, int x) const { //because it maintained a bitwise constness
    *(v2+index) = x;
  }

  const int* const fun(const int* const& p) const;
};

int main(){
  bigArray b;
  return 0;
}
