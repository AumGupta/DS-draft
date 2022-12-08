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
		void push1 (const E& e);
		void push2 (const E& e);
		int pop1();
		int pop2();
		~ArrayStack();
		void display1();
		void display2();
		private:
			E* S;
			int capacity;
			int top1, top2;
};

template<typename E>ArrayStack<E>::ArrayStack(int cap){
	capacity = cap;
	S = new E[cap];
	top1 = -1;
	top2 = cap;
}

template<typename E>ArrayStack<E>::~ArrayStack()
{
	delete[] S;
	cout<<"destructor called"<<endl;
}

template<typename E>
void ArrayStack<E>::push1(const E& e){
	if (top1 < top2 - 1)  
  {  
      top1++;  
    S[top1] = e;  
  }  
  else  
  {  
    cout<<"Stack is full";  
  }  
}

template<typename E>
void ArrayStack<E>::push2(const E& e){
	if (top1 < top2 - 1)  
  {  
      top2--;  
    S[top2] = e;  
  }  
  else  
  {  
    cout<<"Stack is full"; 
  }  
}

template<typename E>
void ArrayStack<E>::display1(){
	cout<<"Elements of first stack: ";  
  	for (int i = top1; i >= 0; --i)  
  	{  
    	cout<<S[i]<<" ";  
  	}
}

template<typename E>
void ArrayStack<E>::display2(){
	cout<<"Elements of first stack: ";  
  	for (int i = top2; i < capacity; i++)  
  	{  
    	cout<<S[i]<<" ";  
  	}
}

template<typename E>
int ArrayStack<E>::pop1(){
	if (top1 >= 0) {
            int x = S[top1];
            top1--;
            return x;
        }
        else {
            cout << "Stack UnderFlow";
        }
}

template<typename E>
int ArrayStack<E>::pop2(){
	if (top2 < capacity) {
            int x = S[top2];
            top2--;
            return x;
        }
        else {
            cout << "Stack UnderFlow" << endl;
        }
}

int main(){
	
	cout<<"*"<<" ------------------- MENU ------------------- *"<<endl;
	cout<<"*"<<"   01) Push elements in the first stack.      *"<<endl;
	cout<<"*"<<"   02) Push elements in the second stack.     *"<<endl;
	cout<<"*"<<"   03) Pop element from the first stack.      *"<<endl;
	cout<<"*"<<"   04) Pop element from the second stack.     *"<<endl;
	cout<<"*"<<"   05) Display elements of the first stack.   *"<<endl;
	cout<<"*"<<"   06) Display elements of the second stack.  *"<<endl;
	cout<<"* -------------------------------------------- *"<<endl;
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
			        obj.push1(val);
				    break;
			}
			case 2:{cout<<"Enter value to be pushed: ";
			        cin>>val;
			        obj.push2(val);
				    break;
			}
			case 3:{cout<<"Pop element of an stack: "<<obj.pop1()<<endl;
				    break;
			}
			case 4:{cout<<"Pop element of an stack: "<<obj.pop2()<<endl;
				    break;
			}
			case 5:{obj.display1();
				break;
			}
			case 6:{obj.display2();
				break;
			}
			default:{cout<<"Invalid value.";
				break;
			}
		}
	}while(k!=11);
	return 0;
}
