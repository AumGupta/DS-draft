#include <iostream>

using namespace std;

template<class T>
class Tridiagonal_Matrix{
	public:
		Tridiagonal_Matrix(int theN = 3);
		~Tridiagonal_Matrix(){
			delete[] element;
		}
		T get(int, int) const;
		void set(int, int, const T&);
		void input();
		void display();
	private:
		int n;
		T *element;
};

template<class T>
Tridiagonal_Matrix<T> :: Tridiagonal_Matrix(int theN){
	if(theN < 1){
		cout<<"Matrix size must be > 0.\n";
	}
	n = theN;
	element = new T[n];
}

template<class T>
T Tridiagonal_Matrix<T> :: get(int i, int j) const{
	if(i < 1 || j < 1 || i > n || j > n){
		cout<<"Matrix size out of bound.\n";
	}
	switch(i-j){
		case 1: {return element[i-2];
			break;
		}
		case 0: {return element[n+i-2];
			break;
		}
		case -1: {return element[2*n+i-2];
			break;
		}
		default:{return 0;
			break;
		}
	}
}

template<class T>
void Tridiagonal_Matrix<T> :: set(int i, int j, const T& newValue){
	if(i < 1 || j < 1 || i > n || j > n){
		cout<<"Matrix size out of bound.\n";
	}
	switch(i-j){
		case 1: {element[i-2] = newValue;
			break;
		}
		case 0: {element[n+i-2] = newValue;
			break;
		}
		case -1: {element[2*n+i-2] = newValue;
			break;
		}
		default: {element[3*n+i-2] = newValue;
			break;
		}
	}
}

template<class T>
void Tridiagonal_Matrix<T> :: input(){
	T val;
	cout<<"Enter the elements of the Diagonal metric array: \n";
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin>>val;
			set(i,j,val);
		}
	}
}

template<class T>
void Tridiagonal_Matrix<T> :: display(){
	cout<<"\nElements of the Diagonal metric array are: \n";
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			T val = get(i,j);
			cout<<val<<"\t";
		}
		cout<<"\n";
	}
}

//int main(){
//	Tridiagonal_Matrix<int> obj;
//	obj.input();
//	obj.display();
//	return 0;
//}
