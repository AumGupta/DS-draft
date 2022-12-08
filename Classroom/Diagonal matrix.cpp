#include <iostream>

using namespace std;

template<class T>
class diagonalMatrix{
	public:
		diagonalMatrix(int theN = 3);
		~diagonalMatrix(){
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
diagonalMatrix<T> :: diagonalMatrix(int theN){
	if(theN < 1){
		cout<<"Matrix size must be > 0.\n";
	}
	n = theN;
	element = new T[n];
}

template<class T>
T diagonalMatrix<T> :: get(int i, int j) const{
	if(i < 1 || j < 1 || i > n || j > n){
		cout<<"Matrix size out of bound.\n";
	}
	if(i==j){
		return element[i-1];
	}
	else{
		return 0;
	}
}

template<class T>
void diagonalMatrix<T> :: set(int i, int j, const T& newValue){
	if(i < 1 || j < 1 || i > n || j > n){
		cout<<"Matrix size out of bound.\n";
	}
	if(i==j){
		element[i-1] = newValue;
	}
	else{
		if(newValue != 0){
			cout<<"Non-diagonal elements must be zero.\n";
		}
	}
}

template<class T>
void diagonalMatrix<T> :: input(){
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
void diagonalMatrix<T> :: display(){
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
//	diagonalMatrix<int> obj;
//	obj.input();
//	obj.display();
//	return 0;
//}
