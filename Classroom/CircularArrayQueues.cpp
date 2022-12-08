#include <iostream>
#define CAP 5

using namespace std;

template<typename T>
class Queue{
	public:
        int front, rear, n;
        T *arr;
	public:
		Queue(){
			front  = -1;
			rear = -1;
			n = 0;
			arr = new T[CAP];
		}
		~Queue(){
			delete []arr;
		}
		int size() const;
		bool empty() const;
		const T& Front() const;
		void enqueue (const T &e);
		void dequeue();
		void display();
};

template <typename T> bool Queue<T> :: empty() const
{
	return (n == 0);
}

template <typename T> int Queue<T> :: size() const
{
	return n;
}

template <typename T> const T& Queue<T> :: Front() const
{
	if(empty()){
		cout<<"Queue Empty.";
	}
	return arr[front+1];
}

template <class T> void Queue<T> :: enqueue(const T &e)
{
	if(size() >= CAP){
		cout<<"STACK IS FULL.";
		return ;	
	}
	rear = (rear+1)%CAP;
	arr[rear] = e;
	n++;
}

template <class T> void Queue<T> :: dequeue()
{
	if(empty()){
		cout<<"Queue is empty.";
	}
	front  = (front+1) % CAP;
	n--;
}

template <class T> void Queue <T> :: display()
{
	if(rear > front){
		for(int i=front+1; i<= rear; i++){
		cout<<arr[i]<<" ";
		}
	}
	else{
		for (int i = front+1; i < CAP; i++)
            cout<<arr[i]<<" ";
  
        for (int i = 0; i <= rear; i++)
            cout<<arr[i]<<" ";
	}
}

int main()
{
	cout<<"* ---------------------- MENU ---------------------- *"<<endl;
	cout<<"*   01) Enqueue an element in the Queue.             *"<<endl;
	cout<<"*   02) Dequeue an element from the Queue.           *"<<endl;
	cout<<"*   03) Display the Queue.                           *"<<endl;
	cout<<"*   04) Return the front element of the Queue.       *"<<endl;
	cout<<"*   05) Call the empty function.                     *"<<endl;
	cout<<"*   06) Call the size function.                      *"<<endl;
	cout<<"* -------------------------------------------------- *"<<endl;
	cout<<endl;
	
	Queue <int>obj;
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
			case 3:{cout<<"Circular Array Queue is : ";
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
