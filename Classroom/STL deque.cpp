#include <iostream>
#include <deque>

using namespace std;

void display(deque<int> deq){
	deque<int> c=deq;
	while (!c.empty())
    {
        cout<<c.front()<<" ";
        c.pop_front();
    }
    cout<<endl;
}

//int main(){
//	cout<<"* ---------------MENU--------------- *"<<endl;
//	cout<<"*  1) Push element at front.         *"<<endl;
//	cout<<"*  2) Push element at back.          *"<<endl;
//	cout<<"*  3) Pop element from front.        *"<<endl;
//	cout<<"*  4) Pop element from back.         *"<<endl;
//	cout<<"*  5) Size of deque.                 *"<<endl;
//	cout<<"*  6) Deque is empty or not.         *"<<endl;
//	cout<<"*  7) Front element of deque.        *"<<endl;
//	cout<<"*  8) Back element of deque.         *"<<endl;
//	cout<<"*  9) Display deque.                 *"<<endl;
//	cout<<"* ---------------------------------- *"<<endl;
//	cout<<endl;
//	
//	deque<int> deq;
//	int k, i;
//	do
//	{
//		cout<<"Enter choice : ";
//		cin>>k;
//		switch(k)
//		{
//			case 1:{cout<<"Enter a number : ";
//					cin>>i;
//					deq.push_front(i);
//					cout<<endl;
//					break;
//			}
//			case 2:{cout<<"Enter a number : ";
//					cin>>i;
//					deq.push_back(i);
//					cout<<endl;
//					break;
//			}
//			case 3:{deq.pop_front();
//					cout<<endl;
//					break;
//			}
//			case 4:{deq.pop_back();
//					cout<<endl;
//					break;
//			}
//			case 5:{cout<<"Size of the deque is : "<<deq.size()<<endl;
//					cout<<endl;
//					break;
//			}
//			case 6:{bool value = deq.empty();
//					if(value == true){
//						cout<<"Stack is empty."<<endl;
//					}
//					else{
//						cout<<"Stack is not empty."<<endl;
//					}
//					cout<<endl;
//					break;
//			}
//			case 7:{cout<<"Front element of deque is : "<<deq.front()<<endl;
//					cout<<endl;
//					break;
//			}
//			case 8:{cout<<"Back element of deque is : "<<deq.back()<<endl;
//					cout<<endl;
//					break;
//			}
//			case 9:{cout<<"Deque is : ";
//					display(deq);
//					cout<<endl;
//				break;
//			}
//			default:{cout<<"Invalid input."<<endl;
//					cout<<endl;
//				break;
//			}
//		}
//	}while(k!=0);
//}
