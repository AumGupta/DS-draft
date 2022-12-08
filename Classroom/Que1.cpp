#include <iostream>
using namespace std;

template <class T>
class Calculate{
T num1;
T num2;
T total;
public:
Calculate(T x, T y){
num1 = x;
num2 = y;
}
void add(){
total = num1+num2;
cout<<"Addition of two numbers is: "<<total;
}
void sub(){
total = num1-num2;
cout<<"Subtraction of two number is: "<<total;
}
void mul(){
total = num1*num2;
cout<<"Multiplication of two number is: "<<total;
}
void div(){
total = num1/num2;
cout<<"Division of two number is: "<<total;
}
};
int main(){
Calculate <double> obj(10.5,2.5);
obj.add();
cout<<endl;
obj.sub();
cout<<endl;
obj.mul();
cout<<endl;
obj.div();
}
