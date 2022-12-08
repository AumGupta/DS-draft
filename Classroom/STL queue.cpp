#include <iostream>
#include <queue>

using namespace std;

void display(queue <int> q)
{
    queue <int> c = q;
    while (!c.empty())
    {
        cout << " " << c.front();
        c.pop();
    }
    cout << "\n";
}

//int main(){
//	cout<<"* ---------------MENU--------------- *"<<endl;
//	cout<<"*  1) Push an element at Queue.      *"<<endl;
//	cout<<"*  2) Pop an element from Queue.     *"<<endl;
//	cout<<"*  3) Front element of the Queue.    *"<<endl;
//	cout<<"*  4) Back element of the Queue.     *"<<endl;
//	cout<<"*  5) Size of the Queue.             *"<<endl;
//	cout<<"*  6) Queue is empty or not.         *"<<endl;
//	cout<<"*  7) Display the Queue.             *"<<endl;
//	cout<<"* ---------------------------------- *"<<endl;
//	cout<<endl;
//	
//	queue<int> que;
//	int i,k;
//	cout<<endl;
//	
//	do{
//		cout<<"Enter choice: "<<endl;
//		cin>>k;
//		switch(k){
//			case 1:{cout<<"Enter value to be pushed : ";
//			        cin>>i;
//			        que.push(i);
//			        cout<<endl;
//					break;
//			}
//			case 2:{que.pop();
//					cout<<endl;
//					break;
//			}
//			case 3:{cout<<"Front element is : "<<que.front()<<endl;
//					cout<<endl;
//					break;
//			}
//			case 4:{cout<<"Back element is : "<<que.back()<<endl;
//					cout<<endl;
//					break;
//			}
//			case 5:{cout<<"Size of the queue is : "<<que.size()<<endl;
//			        cout<<endl;
//				    break;
//			}
//			case 6:{bool result = que.empty();
//					if(result == true){
//						cout<<"Vector is empty.";
//					}
//					else{
//						cout<<"Vector is not empty.";
//					}
//			        cout<<endl;
//				    break;
//			}
//			case 7:{cout<<"Queue is : ";
//					display(que);
//					break;
//			}
//			default:{cout<<"Invalid value.";
//				break;
//			}
//		}
//	}while(k!=0);
//	
//	return 0;
//	
//}
