#include <iostream>
#include <list>

using namespace std;

void display(list<int> lst){
	list<int> d = lst;
	while (!d.empty())
    {
        cout<<d.front()<<" ";
        d.pop_front();
    }
    cout<<endl;
}

//int main(){
//	
//	cout<<"* ---------------MENU--------------- *"<<endl;
//	cout<<"*  1) Push element at front.         *"<<endl;
//	cout<<"*  2) Push element at back.          *"<<endl;
//	cout<<"*  3) Pop element from front.        *"<<endl;
//	cout<<"*  4) Pop element from back.         *"<<endl;
//	cout<<"*  5) Size of the list.              *"<<endl;
//	cout<<"*  6) List is empty or not.          *"<<endl;
//	cout<<"*  7) Front element of the list.     *"<<endl;
//	cout<<"*  8) Back element of the list.      *"<<endl;
//	cout<<"*  9) Display the list.              *"<<endl;
//	cout<<"* ---------------------------------- *"<<endl;
//	cout<<endl;
//	
//	list<int> lst;
//	int k, i;
//	do
//	{
//		cout<<"Enter choice : ";
//		cin>>k;
//		switch(k)
//		{
//			case 1:{cout<<"Enter a number : ";
//					cin>>i;
//					lst.push_front(i);
//					cout<<endl;
//					break;
//			}
//			case 2:{cout<<"Enter a number : ";
//					cin>>i;
//					lst.push_back(i);
//					cout<<endl;
//					break;
//			}
//			case 3:{lst.pop_front();
//					cout<<endl;
//					break;
//			}
//			case 4:{lst.pop_back();
//					cout<<endl;
//					break;
//			}
//			case 5:{cout<<"Size of the list is : "<<lst.size()<<endl;
//					cout<<endl;
//					break;
//			}
//			case 6:{bool value = lst.empty();
//					if(value == true){
//						cout<<"List is empty."<<endl;
//					}
//					else{
//						cout<<"List is not empty."<<endl;
//					}
//					cout<<endl;
//					break;
//			}
//			case 7:{cout<<"Front element of list is : "<<lst.front()<<endl;
//					cout<<endl;
//					break;
//			}
//			case 8:{cout<<"Back element of list is : "<<lst.back()<<endl;
//					cout<<endl;
//					break;
//			}
//			case 9:{cout<<"List is : ";
//					display(lst);
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
