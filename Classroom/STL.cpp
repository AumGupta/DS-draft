#include <iostream>
#include "STL deque.cpp"
#include "STL list.cpp"
#include "STL queue.cpp"
#include "STL stack.cpp"
#include "STL vector.cpp"

using namespace std;

int main(){
	int i,ele;
	deque<int> deq;
	list<int> lst;
	queue<int> que;
	stack<int> stk;
	vector<int> obj;
	do{
		system("CLS");
        cout << "* ----- MAIN MENU ----- *"<<endl;
        cout << "*  1) Deque.            *"<<endl;
        cout << "*  2) List.             *"<<endl;
        cout << "*  3) Queue.            *"<<endl;
        cout << "*  4) Stack.            *"<<endl;
        cout << "*  5) Vector.           *"<<endl;
        cout << "*  6) Exit.             *"<<endl;
        cout << "* --------------------- *"<<endl;
		cout << "Enter choice: ";
		cin>>i;
		switch(i){
			
			
			case 1:{
				system("CLS");
				do{
					cout<<"* -----------------MENU----------------- *"<<endl;
					cout<<"*  1) Push element at front.             *"<<endl;
					cout<<"*  2) Push element at back.              *"<<endl;
					cout<<"*  3) Pop element from front.            *"<<endl;
					cout<<"*  4) Pop element from back.             *"<<endl;
					cout<<"*  5) Size of deque.                     *"<<endl;
					cout<<"*  6) Deque is empty or not.             *"<<endl;
					cout<<"*  7) Front element of deque.            *"<<endl;
					cout<<"*  8) Back element of deque.             *"<<endl;
					cout<<"*  9) Display deque.                     *"<<endl;
					cout<<"* Press 10 to go back to the MAIN MENU.  *"<<endl;
					cout<<"* -------------------------------------- *"<<endl;
					cout<<"Enter choice: ";
					cin>>i;
					switch(i){
						case 1:{cout<<"Enter a number : ";
								cin>>ele;
								deq.push_front(ele);
								cout<<endl;
								break;
						}
						case 2:{cout<<"Enter a number : ";
								cin>>ele;
								deq.push_back(ele);
								cout<<endl;
								break;
						}
						case 3:{deq.pop_front();
								cout<<endl;
								break;
						}
						case 4:{deq.pop_back();
								cout<<endl;
								break;
						}
						case 5:{cout<<"Size of the deque is : "<<deq.size()<<endl;
								cout<<endl;
								break;
						}
						case 6:{bool value = deq.empty();
								if(value == true){
									cout<<"Stack is empty."<<endl;
								}
								else{
									cout<<"Stack is not empty."<<endl;
								}
								cout<<endl;
								break;
						}
						case 7:{cout<<"Front element of deque is : "<<deq.front()<<endl;
								cout<<endl;
								break;
						}
						case 8:{cout<<"Back element of deque is : "<<deq.back()<<endl;
								cout<<endl;
								break;
						}
						case 9:{cout<<"Deque is : ";
								display(deq);
								cout<<endl;
								break;
						}
						default:{cout<<"Invalid value."<<endl;
								cout<<endl;
								break;
						}
					}
				}while(i!=10);
				break;
			}
			
			
			case 2:{
				system("CLS");
				do{
				cout<<"* -----------------MENU----------------- *"<<endl;
				cout<<"*  1) Push element at front.             *"<<endl;
				cout<<"*  2) Push element at back.              *"<<endl;
				cout<<"*  3) Pop element from front.            *"<<endl;
				cout<<"*  4) Pop element from back.             *"<<endl;
				cout<<"*  5) Size of the list.                  *"<<endl;
				cout<<"*  6) List is empty or not.              *"<<endl;
				cout<<"*  7) Front element of the list.         *"<<endl;
				cout<<"*  8) Back element of the list.          *"<<endl;
				cout<<"*  9) Display the list.                  *"<<endl;
				cout<<"* Press 10 to go back to the MAIN MENU.  *"<<endl;
				cout<<"* -------------------------------------- *"<<endl;
				cout<<"Enter choice: ";
				cin>>i;
					switch(i){
						case 1:{cout<<"Enter a number : ";
								cin>>ele;
								lst.push_front(ele);
								cout<<endl;
								break;
							}
						case 2:{cout<<"Enter a number : ";
								cin>>ele;
								lst.push_back(ele);
								cout<<endl;
								break;
						}
						case 3:{lst.pop_front();
								cout<<endl;
								break;
						}
						case 4:{lst.pop_back();
								cout<<endl;
								break;
						}
						case 5:{cout<<"Size of the list is : "<<lst.size()<<endl;
								cout<<endl;
								break;
						}
						case 6:{bool value = lst.empty();
								if(value == true){
									cout<<"List is empty."<<endl;
								}
								else{
									cout<<"List is not empty."<<endl;
								}
								cout<<endl;
								break;
						}
						case 7:{cout<<"Front element of list is : "<<lst.front()<<endl;
								cout<<endl;
								break;
						}
						case 8:{cout<<"Back element of list is : "<<lst.back()<<endl;
								cout<<endl;
								break;
						}
						case 9:{cout<<"List is : ";
								display(lst);
								cout<<endl;
							break;
						}
						default:{cout<<"Invalid value."<<endl;
								cout<<endl;
							break;
						}
					}
				}while(i!=10);
				break;
			}
			
			
			case 3:{
				system("CLS");
				do{
				cout<<"* -----------------MENU----------------- *"<<endl;
				cout<<"*  1) Push an element at Queue.          *"<<endl;
				cout<<"*  2) Pop an element from Queue.         *"<<endl;
				cout<<"*  3) Front element of the Queue.        *"<<endl;
				cout<<"*  4) Back element of the Queue.         *"<<endl;
				cout<<"*  5) Size of the Queue.                 *"<<endl;
				cout<<"*  6) Queue is empty or not.             *"<<endl;
				cout<<"*  7) Display the Queue.                 *"<<endl;
				cout<<"* Press 8 to go back to the MAIN MENU.   *"<<endl;
				cout<<"* -------------------------------------- *"<<endl;
				cout<<"Enter choice: ";
				cin>>i;
					switch(i){
						case 1:{cout<<"Enter value to be pushed : ";
						        cin>>ele;
						        que.push(ele);
						        cout<<endl;
								break;
						}
						case 2:{que.pop();
								cout<<endl;
								break;
						}
						case 3:{cout<<"Front element is : "<<que.front()<<endl;
								cout<<endl;
								break;
						}
						case 4:{cout<<"Back element is : "<<que.back()<<endl;
								cout<<endl;
								break;
						}
						case 5:{cout<<"Size of the queue is : "<<que.size()<<endl;
						        cout<<endl;
							    break;
						}
						case 6:{bool result = que.empty();
								if(result == true){
									cout<<"Vector is empty.";
								}
								else{
									cout<<"Vector is not empty.";
								}
						        cout<<endl;
							    break;
						}
						case 7:{cout<<"Queue is : ";
								display(que);
								break;
						}
						default:{cout<<"Invalid value.";
							break;
						}
					}
				}while(i!=8);
				break;
			}
			
			
		case 4:{
				system("CLS");
				do{
				cout<<"* -----------------MENU----------------- *"<<endl;
				cout<<"*  1) Push element at the stack.         *"<<endl;
				cout<<"*  2) Pop element from the stack.        *"<<endl;
				cout<<"*  3) Size of the stack.                 *"<<endl;
				cout<<"*  4) Stack is empty or not.             *"<<endl;
				cout<<"*  5) Top element of the stack.          *"<<endl;
				cout<<"*  6) Display the stack.                 *"<<endl;
				cout<<"* Press 7 to go back to the MAIN MENU.   *"<<endl;
				cout<<"* -------------------------------------- *"<<endl;
				cout<<"Enter choice: ";
				cin>>i;
					switch(i){
						case 1:{cout<<"Enter a number : ";
								cin>>ele;
								stk.push(ele);
								cout<<endl;
								break;
						}
						case 2:{stk.pop();
								cout<<endl;
								break;
						}
						case 3:{cout<<"Size of the stack is : "<<stk.size()<<endl;
								cout<<endl;
								break;
						}
						case 4:{bool value = stk.empty();
								if(value == true){
									cout<<"Stack is empty."<<endl;
								}
								else{
									cout<<"Stack is not empty."<<endl;
								}
								cout<<endl;
								break;
						}
						case 5:{cout<<"Top element of the stack is : "<<stk.top()<<endl;
								cout<<endl;
								break;
						}
						case 6:{cout<<"Stack is : ";
								display(stk);
								cout<<endl;
								break;
						}
						default:{cout<<"Invalid value."<<endl;
								cout<<endl;
							break;
						}
					}
				}while(i!=7);
				break;
			}
			
			
			case 5:{
				system("CLS");
				do{
				cout<<"* ----------------- MENU ----------------- *"<<endl;
				cout<<"*  01) Push element at back.               *"<<endl;
				cout<<"*  02) Pop element from back.              *"<<endl;
				cout<<"*  03) Front element of the vector.        *"<<endl;
				cout<<"*  04) Back element of the vector.         *"<<endl;
				cout<<"*  05) Display the vector.                 *"<<endl;
				cout<<"*  06) At function of the vector.          *"<<endl;
				cout<<"*  07) operator[] function of the vector.  *"<<endl;
				cout<<"*  08) Vector is empty or not.             *"<<endl;
				cout<<"*  09) Reserve function of the vector.     *"<<endl;
				cout<<"*  10) Size of the vector.                 *"<<endl;
				cout<<"*  11) Re-size of the vector.              *"<<endl;
				cout<<"* Press 12 to go back to the MAIN MENU.    *"<<endl;
				cout<<"* ---------------------------------------- *"<<endl;
				cout<<"Enter choice: ";
				cin>>i;
					switch(i){
						case 1:{cout<<"Enter value to be pushed : ";
						        cin>>ele;
						        obj.push_back(ele);
						        cout<<endl;
							    break;
						}
						case 2:{obj.pop_back();
						        cout<<endl;
							    break;
						}
						case 3:{cout<<"Front element is : "<<obj.front()<<endl;
								cout<<endl;
							    break;
						}
						case 4:{cout<<"Back element is : "<<obj.back()<<endl;
								cout<<endl;
							    break;
						}
						case 5:{cout<<"Vector is : ";
								int i;
								for(i=0;i<obj.size();i++){
									cout<<obj[i]<<" ";
								}
								cout<<endl;
							break;
						}
						case 6:{cout<<"Enter an index : ";
						        cin>>i;
								cout<<"Element is : "<<obj.at(i)<<endl;
								cout<<endl;
								break;
						}
						case 7:{cout<<"Enter an index : ";
						        cin>>i;
								cout<<"Element is : "<<obj.operator[](i)<<endl;
								cout<<endl;
								break;
						}
						case 8:{bool result = obj.empty();
								if(result == true){
									cout<<"Vector is empty.";
								}
								else{
									cout<<"Vector is not empty.";
								}
						        cout<<endl;
								break;
						}
						case 9:{cout<<"Enter the index : ";
						        cin>>i;
								obj.reserve(i);
								cout<<endl;
                            	cout << "The size is: " << obj.size()<<endl;
                            	cout << "The capacity is: " << obj.capacity()<<endl;
								cout<<endl;
								break;
						}
						case 10:{cout<<"Size of the vector is : "<<obj.size();
								cout<<endl;
								break;
						}
						case 11:{cout<<"Enter the size of the vector is : ";
								cin>>i;
								obj.resize(i);
								cout<<endl;
								cout << "The vector is Resized !"<<endl;
								cout << "The size is: " << obj.size()<<endl;
                            	cout << "The capacity is: " << obj.capacity()<<endl;
                            	cout<<endl;
								break;
						}
						default:{cout<<"Invalid value.";
							break;
						}
					}
				}while(i!=12);
				break;
			}
			
			
			default:{cout<<"Program Terminated."<<endl;
						cout<<endl;
						break;
			}	
		}
	}while(i!=6);
	return 0;
}
