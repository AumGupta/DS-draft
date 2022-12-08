#include <iostream>
using namespace std;

class StackEmpty : exception{
	public:
		StackEmpty(const string& err){}
};
class StackFull : exception{
	public:
		StackFull(const string& err){}
};
template<typename E>
class ArrayStack{
	enum {DEF_CAPACITY = 100};
	public:
		ArrayStack(int cap = DEF_CAPACITY);
		ArrayStack(ArrayStack<E> &e);
		bool empty() const;
		int push (const E& e);
		int size() const;
		void display();
		void reverse();
		private:
			E* S;
			int capacity;
			int t;
};
template<typename E>ArrayStack<E>::ArrayStack(int cap)
    : S(new E[cap]), capacity(cap), t(-1){}
    
template<typename E>int ArrayStack<E>::size() const
    {return (t+1);}
    
template<typename E>
int ArrayStack<E>::push(const E& e){
	if(size() == capacity) throw StackFull("PUSH TO FULL STACK");{	
	    S[++t] = e;
	    return e;
	}
	return 0;
} 
   
template<typename E>bool ArrayStack<E>::empty() const
    {return (t<0);}
    
template<typename E>
void ArrayStack<E>::reverse(){
	int A[100];
	if(empty()) throw StackEmpty("POP FROM EMPTY STACK");
	else
	for(int i=0; i<capacity ; i++){
		A[i] =S[--t+1];
	}
	cout<<"Reversed Stack is: ";
	for(int i=0; i<capacity ; i++){
		cout<<A[i]<<" ";
	}
}


int main(){
	
	cout<<"*"<<" ----------------- MENU ----------------- *"<<endl;
	cout<<"*"<<"   1) Push elements in the stack.         *"<<endl;
	cout<<"*"<<"   2) Reverse the elements in the stack.  *"<<endl;
	cout<<"*"<<"   3) Check size of the stack.            *"<<endl;
	cout<<"*"<<"   4) Check stack is empty or not.        *"<<endl;
	cout<<"*"<<"   5) Exit from the program.              *"<<endl;
	cout<<"* ---------------------------------------- *"<<endl;
	cout<<endl;
	int index;
	cout<<"How many elements you need in an array: ";
	cin>> index;
	ArrayStack <int> obj(index);
	int k;
	int val;
	cout<<endl;
	
	do{
		cout<<"Enter choice: "<<endl;
		cin>>k;
		switch(k){
			case 1:{cout<<"Enter value to be pushed: ";
			        cin>>val;
			        obj.push(val);
				    break;
			}
			case 2:{obj.reverse();
				    break;
			}
			case 3:{cout<<"Size of the stack: "<<obj.size()<<" elements"<<endl;
				break;
			}
			case 4:{cout<<"Stack is : "<<obj.empty()<<endl;
				break;
			}
			case 5:{cout<<"EXIT from the program.";
				break;
			}
			default:{cout<<"Invalid value.";
				break;
			}
		}
	}while(k!=2);
	return 0;
}
