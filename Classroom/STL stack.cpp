#include <iostream>
#include <stack>

using namespace std;

void display(stack<int> que){
	stack<int> a=que;
	while (!a.empty())
    {
        cout<<a.top()<<" ";
        a.pop();
    }
}

//int main(){
//	cout<<"* ---------------MENU--------------- *"<<endl;
//	cout<<"*  1) Push element at the stack.     *"<<endl;
//	cout<<"*  2) Pop element from the stack.    *"<<endl;
//	cout<<"*  3) Size of the stack.             *"<<endl;
//	cout<<"*  4) Stack is empty or not.         *"<<endl;
//	cout<<"*  5) Top element of the stack.      *"<<endl;
//	cout<<"*  6) Display the stack.             *"<<endl;
//	cout<<"* ---------------------------------- *"<<endl;
//	cout<<endl;
//	
//	stack<int> stk;
//	int k,i;
//	do
//	{
//		cout<<"Enter choice : ";
//		cin>>k;
//		switch(k)
//		{
//			case 1:{cout<<"Enter a number : ";
//					cin>>i;
//					stk.push(i);
//					cout<<endl;
//					break;
//			}
//			case 2:{stk.pop();
//					cout<<endl;
//					break;
//			}
//			case 3:{cout<<"Size of the stack is : "<<stk.size()<<endl;
//					cout<<endl;
//					break;
//			}
//			case 4:{bool value = stk.empty();
//					if(value == true){
//						cout<<"Stack is empty."<<endl;
//					}
//					else{
//						cout<<"Stack is not empty."<<endl;
//					}
//					cout<<endl;
//					break;
//			}
//			case 5:{cout<<"Top element of the stack is : "<<stk.top()<<endl;
//					cout<<endl;
//					break;
//			}
//			case 6:{cout<<"Stack is : ";
//					display(stk);
//					break;
//			}
//			default:{cout<<"Invalid input."<<endl;
//					cout<<endl;
//				break;
//			}
//		}
//	}while(k!=0);
//}
