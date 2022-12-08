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
class Clist
{
	private:
		node<T> *tail;
	public:
		Clist(){
			tail = NULL;
		}
		~Clist();
		bool isempty();
		void add_front(T el);
		void add(T el1,T el2);
		void add_back(T el);
		T delete_back();
		T delete_front();
		void delete_node(T el);
		bool search(T el);
		void concat(Clist &obj, Clist &obj2);
	    void reverse();
	    void display();
		int count();
		void delete_loc(int loc);
};

template <class T> Clist<T> :: ~Clist()
{
	node<T> *p, *q;
	p = tail -> next;
	while(p != tail)
	{
		q = p;
		p = p -> next;
		delete q;
	}
	delete tail;
} 

template <class T> bool Clist<T> :: isempty()
{
	return (tail == NULL);
}

template <class T> void Clist<T> :: add_front(T el)
{
	if(isempty())
	{
		tail = new node <T> (el);
		tail -> next = tail;
	}
	else
	{
		tail -> next = new node <T> (el, tail -> next);
	}
}

template <class T> void Clist<T> :: add(T el1, T el2)
{
	node<T> *newNode = new node<T>(el2);
    
	    node <T> *temp = tail;
	    while(temp -> info != el1)
	    {
	    	temp = temp -> next;
		}
	    newNode->next = temp->next;
        temp->next = newNode;
}

template <class T> void Clist<T> :: add_back(T el)
{
	if(isempty())
	{
		tail = new node<T>(el);
		tail -> next = tail;
	}
	else
	{
		tail -> next = new node<T>(el, tail -> next); 
		tail = tail -> next;
	}
}

template <class T> T Clist <T> :: delete_back()
{
	T el = tail -> info;
	if(tail -> next == tail)
	{
		delete tail;
		tail = NULL;
	}
	else
	{
		node<T> *temp = tail -> next;
		for(; temp -> next != tail; temp = temp -> next);
		temp -> next = tail -> next;
		delete tail;
		tail = temp;
	}
	return el;
}

template <class T> T Clist<T> :: delete_front()
{
	node <T> *temp = tail -> next;
	T el = temp -> info;
	if(temp -> next == tail)
	{
		tail = NULL;
	}
	else
	{
		tail -> next =temp -> next;
	}
	delete temp;
	return el;
}

template <class T> void Clist<T> :: delete_node(T el)
{
	if(tail != NULL)
	{
		if(tail == tail -> next && el == tail -> info)
		{
			delete tail;
			tail = NULL;
		}
		else if(el == tail -> next -> info)
		{
			node <T> *temp = tail -> next;
			tail -> next = temp -> next;
			delete temp;
		}
		else
	    {
		    node <T> *pred, *temp;
		    for(pred = tail -> next, temp = pred -> next; temp != tail -> next  && !(temp -> info == el); pred = pred -> next, temp = temp -> next);
			if(temp != NULL)
			{
				pred -> next = temp -> next;
				if(temp !=  tail -> next)
				{
					pred -> next = temp -> next;
					if(temp == tail)
					{
						tail != pred;
					}
					else
					{
						delete temp;
					}
				}
			}
		}
	}
}

template <class T> bool Clist <T> :: search(T el)
{
	node<T> *temp;
	for(temp = tail; temp->next != tail && !(temp -> info == el); temp = temp -> next);
	if(temp -> info == el)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T> void Clist <T> :: concat(Clist<T> &obj, Clist<T> &obj2)
{
	node<T> *temp = obj2.tail -> next;
	for(temp = obj2.tail -> next; temp != obj2.tail; temp = temp -> next)
	{
		obj.add_back(temp -> info);
	}
	obj.add_back(temp -> info);
}

template <class T> void Clist <T> :: reverse()
{
	if(isempty())
	{
		return;
	}
	node<T> *q, *r,*s, *t;
	t = q = tail -> next;
	tail -> next = NULL;
	r = NULL;
	do
	{
		s = r;
		r = q;
		q = q -> next;
		r -> next = s;
		t -> next = r;
	}while(q != NULL);
	tail = t;
}

template <class T> void Clist <T> :: display()
{
	node<T> *temp;
	for(temp = tail -> next; temp != tail; temp = temp->next)
	{
		cout<< temp -> info<< " ";
	}
	cout << temp->info;
	cout<<endl;
}

template <class T> int Clist <T> :: count()
{
	int count = 0;
	if(tail == NULL)
	{
		return count;
	}
	node <T> *temp;
	temp = tail -> next;
	do
	{
		count++;
		temp = temp -> next;
	}while(temp != tail -> next);
	
	return count;
}

template <class T> void Clist<T> :: delete_loc(int loc)
{
    if(loc == 0)
    {
        delete_front();
    }
    else
    {
	    node <T> *temp = tail;
	    node <T> *n = tail -> next;
	    for(int i=0; i<loc-2; i++)
	    {
	     	temp = temp -> next;
	     	n = n -> next;
	    }
	    temp -> next = n -> next;
	    delete n;
	    return ;
    }
}



int main()
{
	cout<<"* --------------------------------- MENU --------------------------------- *"<<endl;
	cout<<"*   01) Insert an element x at the front of the linked list.               *"<<endl;
	cout<<"*   02) Insert an element x after an element y in the linked list.         *"<<endl;
	cout<<"*   03) Insert an element x at the back of the linked list.                *"<<endl;
	cout<<"*   04) Remove an element from the front of the linked list.               *"<<endl;
	cout<<"*   05) Remove an element from the back of the linked list.                *"<<endl;
	cout<<"*   06) Remove an element with a specific value.                           *"<<endl;
	cout<<"*   07) Search for an element.                                             *"<<endl;
	cout<<"*   08) Concatenate two linked lists.                                      *"<<endl;
	cout<<"*   09) Reverse the linked list.                                           *"<<endl;
	cout<<"*   10) Display the linked list.                                           *"<<endl;
	cout<<"*   11) Count the number of elements in the linked list.                   *"<<endl;
	cout<<"*   12) Remove an element from the specific location in the linked list.   *"<<endl;
	cout<<"* ------------------------------------------------------------------------ *"<<endl;
	cout<<endl;
	
	Clist<int> obj,obj2;
	int k;
	int val1,val2,loc;
	//values for second linked-list
	obj2.add_front(5);
	obj2.add_front(9);
	obj2.add(9,1);
	obj2.add_back(10);
	
	do{
		cout<<"Enter choice: "<<endl;
		cin>>k;
		switch(k){
			case 0:{cout<<"Program terminated.";
				    break;
			}
			case 1:{cout<<"Enter an element to add at the front : ";
			        cin>>val1;
			        obj.add_front(val1);
			    	cout<<endl;
				    break;
			}
			case 2:{cout<<"Enter an element after which a new element needs to be added (y element) : ";
			        cin>>val1;
			        cout<<"Enter a new element (x element) : ";
			        cin>>val2;
			        obj.add(val1, val2);
			        cout<<"Adding element x after element y, Circular singly linked list is : ";
			    	obj.display();
			    	cout<<endl;
				    break;
			}
			case 3:{cout<<"Enter an element to add at the back : ";
			        cin>>val1;
			        obj.add_back(val1);
			    	cout<<endl;
				    break;
			}
			case 4:{cout<<"Delete an element from the back. ";
			        cout<<endl;
			        obj.delete_back();
			        cout<<"Circular singly linked list after deleting an element from the back : ";
			    	obj.display();
			    	cout<<endl;
				    break;
			}
			case 5:{cout<<"Delete an element from the front. ";
			        cout<<endl;
			        obj.delete_front();
			        cout<<"Circular singly linked list after deleting an element from the front : ";
			    	obj.display();
			    	cout<<endl;
				    break;
			}
			case 6:{cout<<"Enter an element which you want to delete : ";
			        cin>>val1;
			    	obj.delete_node(val1);
			    	cout<<endl;
			    	cout<<"Circular singly linked list after deleting the specific element : ";
			    	obj.display();
			    	cout<<endl;
				    break;
			}
			case 7:{cout<<"Search for an element : ";
			        cin>>val1;
			        bool result = obj.search(val1);
			        if(result == true){
			        	cout<<"Element is in the linked list."<<endl;
					}
					else{
						cout<<"Element is not in the linked list."<<endl;
					}
					cout<<endl;
				    break;
			}
			case 8:{obj.concat(obj, obj2);
					cout<<"Circular singly linked list after concatination is : ";
					obj.display();
					cout<<endl;
		   			break;
			}
			case 9:{obj.reverse();
			        cout<<"Reversed circular singly linked list is : ";
			        obj.display();
			        cout<<endl;
				    break;
			}
			case 10:{cout<<"Circular singly linked list is : ";
			        obj.display();
				    cout<<endl;
				     break;
			}
			case 11:{cout<<"Number of elements in the linked list are : "<<obj.count();
			         cout<<endl;
					 break;
			}
			case 12:{cout<<"Enter the location : ";
			        cin>>loc;
			        obj.delete_loc(loc);
			        cout<<"Circular singly linked list after deleting an element from a specific location is : ";
			        obj.display();
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
