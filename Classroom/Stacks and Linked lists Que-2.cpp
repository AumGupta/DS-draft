#include <iostream>

using namespace std;

template <class T>
class node
{
	public:
		T info;
		node<T> *next;
		node(T el, node<T> *ptr = NULL)
		{
			info = el;
			next = ptr;
		}
};

template <class T>
class Slist
{
	private:
		node<T> *bottom, *top;
	public:
		Slist(){
			bottom = top = NULL;
		}
		int size();
		bool empty();
		void push(int value);
		void display();
		int pop();
		int top_ele();
		bool clear();
};

template <class T> int Slist <T> :: size()
{
	node<T> *temp;
	int count = 0;
	for(temp = bottom; temp != NULL ; temp = temp -> next)
	{
		count = count + 1;
	}
	return count;
}

template <class T> bool Slist <T> :: empty()
{
	if(top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T> bool Slist <T> :: clear(){
	if(bottom == NULL){
		return true;
	}
	else{
		pop();
		clear();
	}
}

template <class T> void Slist <T> :: push(int value)           //add tail
{
	if(top != NULL)
	{
		top -> next = new node<T>(value);
		top = top -> next;
	}
	else
	{
		bottom = top = new node<T>(value);
	}
}

template <class T> int Slist <T> :: pop()                        //delete head
{
	T el = top -> info;
	if(bottom == top)
	{
		delete bottom;
		bottom = top = NULL;
	}
	else
	{
		node<T> *temp = bottom;
		for(temp = bottom; temp -> next != top; temp = temp -> next);
		delete top;
		top = temp;
		top -> next = NULL;
	}
	return el;
}

template <class T> void Slist <T> :: display()
{
	node<T> *temp;
	for(temp = bottom; temp != NULL ; temp = temp -> next)
	{
		cout<< temp -> info<< " ";
	}
}

template <class T> int Slist <T> :: top_ele()
{
	T el = top -> info;
	if(top == NULL){
		cout<<"Top of empty stack.";
	}
	else{
		return el;
	}
}

int main()
{
	cout<<"*"<<" ------------------ MENU ------------------ *"<<endl;
	cout<<"*"<<"   01) Push elements into the stack         *"<<endl;
	cout<<"*"<<"   02) Pop elements from the stack.         *"<<endl;
	cout<<"*"<<"   03) Find top element of the stack.       *"<<endl;
	cout<<"*"<<"   04) Call the display function.           *"<<endl;
	cout<<"*"<<"   05) Call the clear function.             *"<<endl;
	cout<<"*"<<"   06) Check size of the stack.             *"<<endl;    
	cout<<"*"<<"   07) Check stack is empty or not.         *"<<endl;     
	cout<<"*"<<"   08) Exit from the program.               *"<<endl;
	cout<<"* ------------------------------------------ *"<<endl;
	cout<<endl;
	
	Slist<int> obj;
	int k;
	int val,loc;
	
	do{
		cout<<"Enter choice: "<<endl;
		cin>>k;
		switch(k){
			case 0:{cout<<"Program terminated.";
				    break;
			}
			case 1:{cout<<"Enter an element to add in the stack: ";
			        cin>>val;
			        obj.push(val);
			        cout<<endl;
				    break;
			}
			case 2:{cout<<"Poped element is: "<<obj.pop();
					cout<<endl;
					break;
			}
			case 3:{cout<<"Element at top is: "<<obj.top_ele();
					cout<<endl;
					break;
			}
			case 4:{cout<<"Stack is: ";
					obj.display();
					cout<<endl;
					break;
			}
			case 5:{bool value = obj.clear();
			        if(value == true){
			        	cout<<"Stack is clear.";
			        	cout<<endl;
					}
					else{
						cout<<"Stack is not clear.";
						cout<<endl;
					}
					cout<<endl;
					break;
			}
			case 6:{cout<<"Total elements in an array is: "<<obj.size();
					cout<<endl;
					break;
			}
			case 7:{bool value = obj.empty();
			        if(value == true){
			        	cout<<"Stack is empty.";
			        	cout<<endl;
					}
					else{
						cout<<"Stack is not empty.";
						cout<<endl;
					}
					break;
			}
			default:{cout<<"Invalid Number.";
					cout<<endl;
					break;
			}
		}
	}while(k!=0);
	return 0;
}
