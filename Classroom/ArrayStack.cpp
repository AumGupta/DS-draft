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
		int size() const;
		bool empty() const;
		const E& top() const;
		int push (const E& e);
		const ArrayStack<E>& operator = (ArrayStack<E>&);
		int pop();
		~ArrayStack();
		void display();
		void clear();
		private:
			E* S;
			int capacity;
			int t;
};

template<typename E>ArrayStack<E>::ArrayStack(int cap)
    : S(new E[cap]), capacity(cap), t(-1){}
    
template<typename E>ArrayStack<E>::~ArrayStack()
{
	delete[] S;
	cout<<"destructor called"<<endl;
}

template<typename E>ArrayStack<E>::ArrayStack(ArrayStack<E> &e)
    : S(new E[e.capacity]), capacity(e.capacity), t(-1){
		cout<<"copy constructor called : ";
	    for(int i=0; i<capacity; i++){
		    this->push(e.S[i]);
	    }
    }
    
template<typename E> const ArrayStack<E>& ArrayStack<E> :: operator = (ArrayStack<E> &e)
    {
		cout<<"Overloading assignment operator gets called "<<endl;
		cout<<"Assign all the elements of one stack to the other"<<endl;
	    for(int i=0; i<e.capacity; i++){
		    S[i] = this->push(e.S[i]);
	    }
	    display();
    }
    
template<typename E>int ArrayStack<E>::size() const
    {return (t+1);}
    
template<typename E>bool ArrayStack<E>::empty() const
    {return (t<0);}
    
template<typename E>
const E& ArrayStack<E>::top() const{
	if(empty()) throw StackEmpty("TOP OF EMPTY STACK");
	return S[t];
}

template<typename E>
int ArrayStack<E>::push(const E& e){
	if(size() == capacity) throw StackFull("PUSH TO FULL STACK");{	
	    S[++t] = e;
	    return e;
	}
	return 0;
}

template<typename E>
void ArrayStack<E>::display(){
	for(int i=0; i<size(); i++){
		cout<<S[i]<<" ";
	}
}

template<typename E>
void ArrayStack<E>::clear(){
	delete[] S;
	t = -1;
	S = new E[size()];
	cout<<"ALL ELEMENTS OF AN ARRAY GETS CLEARED."<<endl;
}

template<typename E>
int ArrayStack<E>::pop(){
	if(empty()) throw StackEmpty("POP FROM EMPTY STACK");
	else
	cout<<"Poped element is: "<<S[t]<<endl;
	return --t;
}

int main(){
	
	cout<<"*"<<" ------------------ MENU ------------------ "<<"*"<<endl;
	cout<<"*"<<"   01) Push elements in the stack."<<"          *"<<endl;
	cout<<"*"<<"   02) Pop elements from the stack."<<"         *"<<endl;
	cout<<"*"<<"   03) Top element of the stack."<<"            *"<<endl;
	cout<<"*"<<"   04) Call the display function.           *"<<endl;
	cout<<"*"<<"   05) Call the clear function.             *"<<endl;
	cout<<"*"<<"   06) Copy constructor.                    *"<<endl;
	cout<<"*"<<"   07) Overloading assignment operator.     *"<<endl;
	cout<<"*"<<"   08) Call the destructor."<<"                 *"<<endl;
	cout<<"*"<<"   09) Check size of the stack.             *"<<endl;    
	cout<<"*"<<"   10) Check stack is empty or not.         *"<<endl;     
	cout<<"*"<<"   11) Exit from the program."<<"               *"<<endl;
	cout<<"* ------------------------------------------ *"<<endl;
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
			case 2:{obj.pop();
				    break;
			}
			case 3:{cout<<"Top element of an stack: "<<obj.top()<<endl;
				    break;
			}
			case 4:{obj.display();
			        cout<<endl;
				    break;
			}
			case 5:{obj.clear();
				break;
			}
			case 6:{ArrayStack <int> obj1(obj);
			        cout<<endl;
			        obj1.display();
			        cout<<endl;
				break;
			}
			case 7:{ArrayStack <int> obj2(index);
			        cout<<endl;
			        obj2 = obj;
			        cout<<endl;
				break;
			}
			case 8:{obj.~ArrayStack();
				break;
			}
			case 9:{cout<<"Size of the stack: "<<obj.size()<<" elements"<<endl;
				break;
			}
			case 10:{cout<<"Stack is : "<<obj.empty()<<endl;
				break;
			}
			case 11:{cout<<"EXIT from the program."<<endl;
				break;
			}
			default:{cout<<"Invalid value.";
				break;
			}
		}
	}while(k!=11);
	return 0;
}
