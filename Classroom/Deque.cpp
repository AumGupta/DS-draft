#include <iostream>
#include "DSlist.cpp"

using namespace std;

typedef int Elem;
class LinkedDeque{
	public:
		LinkedDeque();
		int size() const;
		bool empty() const;
		const Elem& Front() const;
		const Elem& Back() const;
		void insertFront(const Elem& e);
		void insertBack(const Elem& e);
		void removeFront();
		void removeBack();
		void display();
	private:
		DSlist C;
		int n;
};

LinkedDeque :: LinkedDeque()
	:C(), n(0) { }

int LinkedDeque :: size() const
{return n;}

bool LinkedDeque :: empty() const
{return n == 0;}

const Elem& LinkedDeque :: Front() const{
	cout<<"Front element of the Deque is : ";
	C.Front();
}

const Elem& LinkedDeque :: Back() const{
	cout<<"Back element of the Deque is : ";
	C.Back();
}

void LinkedDeque :: insertFront(const Elem& e){
	C.add_head(e);
	n++;
}

void LinkedDeque :: insertBack(const Elem& e){
	C.add_tail(e);
	n++;
}

void LinkedDeque :: removeFront(){
	if(empty()){
		cout<<"Front is empty";
	}
	else{
		C.delete_head();
		n--;
	}
}

void LinkedDeque :: removeBack(){
	if(empty()){
		cout<<"Back is empty";
	}
	else{
		C.delete_tail();
		n--;
	}
}

void LinkedDeque :: display(){
	C.display();
}

int main(){
	
	cout<<"* ----------------------- MENU ----------------------- *"<<endl;
	cout<<"*   01) Insert an element at the beginning of Deque.   *"<<endl;
	cout<<"*   02) Insert an element at the end of Deque.         *"<<endl;
	cout<<"*   03) Remove the first element of Deque.             *"<<endl;
	cout<<"*   04) Remove the last element of Deque.              *"<<endl;
	cout<<"*   05) Display the Queue.                             *"<<endl;
	cout<<"*   06) Return the front element of the Queue.         *"<<endl;
	cout<<"*   07) Return the back element of the Queue.          *"<<endl;
	cout<<"*   08) Call the empty function.                       *"<<endl;
	cout<<"*   09) Call the size function.                        *"<<endl;
	cout<<"* ---------------------------------------------------- *"<<endl;
	cout<<endl;
	
	LinkedDeque obj;
	int k;
	int val;
	
	do{
		cout<<"Enter choice: "<<endl;
		cin>>k;
		switch(k){
			case 0:{cout<<"Program terminated.";
				    break;
			}
			case 1:{cout<<"Enter an element : ";
			        cin>>val;
			        obj.insertFront(val);
			        cout<<endl;
				    break;
			}
			case 2:{cout<<"Enter an element : ";
			        cin>>val;
			        obj.insertBack(val);
			        cout<<endl;
				    break;
			}
			case 3:{cout<<"Delete the first element of Deque.";
			        cout<<endl;
			        obj.removeFront();
			        cout<<endl;
				    break;
			}
			case 4:{cout<<"Delete the end element of Deque.";
			        cout<<endl;
			        obj.removeBack();
			        cout<<endl;
				    break;
			}
			case 5:{cout<<"Deque is : ";
			        obj.display();
				    cout<<endl;
				     break;
			}
			case 6:{obj.Front();
				    cout<<endl;
				     break;
			}
			case 7:{obj.Back();
				    cout<<endl;
				     break;
			}
			case 8:{bool result = obj.empty();
					if(result == true){
						cout<<"Deque is EMPTY.";
					}
					else{
						cout<<"Deque is not EMPTY.";
					}
			         cout<<endl;
				     break;
			}
			case 9:{cout<<"Size of the Deque is : "<<obj.size();
			         cout<<endl;
					 break;
			}
			default:{cout<<"Invalid value.";
				    break;
			}
		}
	}while(k!=0);
	return 0;
}
