#include <iostream>
using namespace std;

template <class T>
void array_s(T arr[],int a, int b, int c)
{
T sum;
for(int i = c; i<=b; i++){
sum += arr[i];
}
cout<<"Sum is : "<<sum;
}
template <class T>
void array_i(int a)
{
int num;
T arr[10];
for(int i = 0; i<a; i++){
	cout<<"Enter the "<<i<<" element: ";
    cin>>arr[i];
}
cout<<endl;
cout<<"Final matrix is: ";
cout<<endl;
for(int i = 0; i<a; i++){
cout<<arr[i]<<" ";
}
cout<<endl;
cout<<"From where you need the sum, please enter the index:";
cin>>num;
array_s<int>(arr,0,a-1,num);
}
int main(){
int a;
cout<<"Enter the total number of elements you required in your array: ";
cin>>a;
array_i<int>(a);
}
