#include <iostream>
using namespace std;

template <typename T>
class Dollar;

template <typename T>
class Rupee
{
public:
    T price;

    Rupee()
    {
        price = 10;
    }
    T &operator=(Dollar<T> &obj)
    {
        price = obj.price * 79.71;
        return price;
    }
};
template <typename T>
class Dollar
{
public:
    T price;

    Dollar()
    {
        price = 10;
    }

    T &operator=(Rupee<T> &obj)
    {
        price = obj.price / 79.71;
        return price;
    }
};
int main(){
	
	Rupee<float> r1, r2;
    Dollar<float> d1, d2;
    
    cout<<"Orignal value of US Dollar and Indian Rupee is: "<<endl;
	cout << "d1: $" << d1.price << endl;
    cout << "d2: $" << d2.price << endl;
    cout << "r1: Rs." << r1.price << endl;
    cout << "r2: Rs." << r2.price << endl;

    cout << endl;

    d1 = r2;
    r1 = d2;

    cout << "After converting taking 79.71 as constant value of US Dollar: "<<endl;
    cout << "d1: Rs." << d1.price << endl;
    cout << "d2: $" << d2.price << endl;
    cout << "r1: $" << r1.price << endl;
    cout << "r2: Rs." << r2.price << endl;

    return 0;
}
