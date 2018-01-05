
#include<iostream>

class Collar{};
class dog{
  Collar* pCollar;
  dog& operator =(const dog& rhs){
    if(this == &rhs)
      return *this;

    Collar* pOrigCollar = pCollar;
    pCollar = new Collar(*rhs.pCollar);
    delete pOrigCollar;
    return *this;
  }
};


int main(){

  return 0;

}
