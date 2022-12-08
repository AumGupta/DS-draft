#include <iostream>
#include <vector>

using namespace std;

//int main(){
//	cout<<"* ----------------- MENU ----------------- *"<<endl;
//	cout<<"*  01) Push element at back.               *"<<endl;
//	cout<<"*  02) Pop element from back.              *"<<endl;
//	cout<<"*  03) Front element of the vector.        *"<<endl;
//	cout<<"*  04) Back element of the vector.         *"<<endl;
//	cout<<"*  05) Display the vector.                 *"<<endl;
//	cout<<"*  06) At function of the vector.          *"<<endl;
//	cout<<"*  07) operator[] function of the vector.  *"<<endl;
//	cout<<"*  08) Vector is empty or not.             *"<<endl;
//	cout<<"*  09) Reserve function of the vector.     *"<<endl;
//	cout<<"*  10) Size of the vector.                 *"<<endl;
//	cout<<"*  10) Re-size of the vector.              *"<<endl;
//	cout<<"* ---------------------------------------- *"<<endl;
//	cout<<endl;
//	
//	vector<int> obj;
//	int i,k;
//	cout<<endl;
//	
//	do{
//		cout<<"Enter choice: "<<endl;
//		cin>>k;
//		switch(k){
//			case 1:{cout<<"Enter value to be pushed : ";
//			        cin>>i;
//			        obj.push_back(i);
//			        cout<<endl;
//				    break;
//			}
//			case 2:{obj.pop_back();
//			        cout<<endl;
//				    break;
//			}
//			case 3:{cout<<"Front element is : "<<obj.front()<<endl;
//					cout<<endl;
//				    break;
//			}
//			case 4:{cout<<"Back element is : "<<obj.back()<<endl;
//					cout<<endl;
//				    break;
//			}
//			case 5:{cout<<"Vector is : ";
//					int i;
//					for(i=0;i<obj.size();i++){
//						cout<<obj[i]<<" ";
//					}
//					cout<<endl;
//				break;
//			}
//			case 6:{cout<<"Enter an index : ";
//			        cin>>i;
//					cout<<"Element is : "<<obj.at(i)<<endl;
//					cout<<endl;
//					break;
//			}
//			case 7:{cout<<"Enter an index : ";
//			        cin>>i;
//					cout<<"Element is : "<<obj.operator[](i)<<endl;
//					cout<<endl;
//					break;
//			}
//			case 8:{bool result = obj.empty();
//					if(result == true){
//						cout<<"Vector is empty.";
//					}
//					else{
//						cout<<"Vector is not empty.";
//					}
//			        cout<<endl;
//					break;
//			}
//			case 9:{cout<<"Enter the index : ";
//			        cin>>i;
//					obj.reserve(i);
//					cout<<endl;
//					break;
//			}
//			case 10:{cout<<"Size of the vector is : "<<obj.size();
//					cout<<endl;
//					break;
//			}
//			case 11:{cout<<"Enter the size of the vector is : ";
//					cin>>i;
//					obj.resize(i);
//					cout<<endl;
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
