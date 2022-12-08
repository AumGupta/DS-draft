#include <iostream>
#include "Sentinels nodes.cpp"

using namespace std;

typedef int Elem;
class LinkedQueue{
	public:
		LinkedQueue();
		int size() const;
		bool empty() const;
		const Elem& Front() const;
		void enqueue(const Elem &e);
		void dequeue();
		void display();
	private:
		Clist C;
		int n;
};

LinkedQueue :: LinkedQueue()
	:C(), n(0) { }

int LinkedQueue :: size() const
{return n;}

bool LinkedQueue :: empty() const
{return n == 0;}

const Elem& LinkedQueue :: Front() const{
	if(empty()){
		cout<<"Front is empty";
	}
	else{
		return C.Front();
	}
}

void LinkedQueue :: enqueue(const Elem& e){
	C.add(e);
	C.advance();
	n = n + 1;
}

void LinkedQueue :: dequeue(){
	if(empty()){
		cout<<"Dequeue is empty.";
	}
	C.remove();
	n = n-1;
}

void LinkedQueue :: display(){
	C.display();
}

int main(){
	
	cout<<"* ---------------------- MENU ---------------------- *"<<endl;
	cout<<"*   01) Enqueue an element in the Queue.             *"<<endl;
	cout<<"*   02) Dequeue an element from the Queue.           *"<<endl;
	cout<<"*   03) Display the Queue.                           *"<<endl;
	cout<<"*   04) Return the front element of the Queue.       *"<<endl;
	cout<<"*   05) Call the empty function.                     *"<<endl;
	cout<<"*   06) Call the size function.                      *"<<endl;
	cout<<"* -------------------------------------------------- *"<<endl;
	cout<<endl;
	
	LinkedQueue obj;
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
			        obj.enqueue(val);
			        cout<<endl;
				    break;
			}
			case 2:{cout<<"Deleting an element from the queue.";
			        cout<<endl;
			        obj.dequeue();
			        cout<<endl;
				    break;
			}
			case 3:{cout<<"Circular Linked Queue is : ";
			        obj.display();
				    cout<<endl;
				     break;
			}
			case 4:{cout<<"Front element of the Queue is : "<<obj.Front();
				    cout<<endl;
				     break;
			}
			case 5:{bool result = obj.empty();
					if(result == true){
						cout<<"Queue is EMPTY.";
					}
					else{
						cout<<"Queue is not EMPTY.";
					}
			         cout<<endl;
				     break;
			}
			case 6:{cout<<"Size of the Queue is : "<<obj.size();
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
