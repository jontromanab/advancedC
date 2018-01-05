
#include<iostream>
/*
1. Static_cast

int i = 9;
float f = static_cast<float>(i);
dog d1 = static_cast<dog>(string("Bob"));
dog* pd = static_cast<dog*>(new yellowdog());

//conver object from one type to another
Type conversion needs to be defined
conver pointer/reference from one type to a related type(down/up cast)


2. Dynamic cast

dog* pd = new yellowdog();
yellodog py = dynamic_cast<yellowdog*>(pd);

a. It converts pointer/ref from one type to a related type(down cast) base->derived
b. run-time type check. If succeed, py==pdl ;if fail, py==0
c. It requires the 2 types to be polymorphic(have virtual functions)

3. const cast

const char* str = "hello";
char* modifiable =const_cast<char*>(str);

only works on pointer/ref
only owrks on same typedefcast away constness of the object begin pointed to

4. reinterpret_cast

long p = 511110980;
dog* dd = reinterpret_cast<dog*>(p);
//reinterpret the bits of the object pointed to the ultimate cast that can cast one pointer
to other type of pointer

C-style casting

short a =2000;
int i = (int)a; //c-style cast notation
int j = int(a); //functional notation

*/

int main(){
  return 0;
}
