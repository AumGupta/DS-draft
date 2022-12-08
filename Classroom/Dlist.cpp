#include <iostream>

using namespace std;

template <class T>
class node
{
	public:
		T info;
		node<T> *next;
		node<T> *prev;
		node(T el, node<T> *p = NULL, node<T> *n = NULL)
		{
			info = el;
			next = n;
			prev = p;
		}
};

template <class T>
class Dlist
{
	private:
		node<T> *head, *tail;
	public:
		Dlist(){
			head = tail = NULL;
		}
		~Dlist();
		bool isempty();
		void add_head(T el);
		void add(int loc,T el);
		void add_tail(T el);
		T delete_head();
		void delete_loc(int loc);
		T delete_tail();
		bool search(T el);
		void concat(Dlist &obj, Dlist &obj2);
		void delete_node(T el);
		void display();
	    void reverse();
	    int count();
};

template <class T> bool Dlist<T> :: isempty()
{
	return (head == NULL);
}

template <class T> Dlist<T> :: ~Dlist()
{
	node<T> *p;
	while(!isempty())
	{
		p = head -> next;
		delete head;
		head = p;
	}
}

template <class T> void Dlist<T> :: add_head(T el)
{
	if(head != NULL)
	{
		head = new node<T> (el, NULL, head);
		head -> next -> prev = head;
	}
	else
	{
		head = tail = new node<T>(el);
	}
}

template <class T> void Dlist<T> :: add(int loc, T el)
{
	node<T> *newNode = new node<T>(el);
    if(loc == 0)
    {
        add_head(el);
    }
    else if(loc == count())
    {
        add_tail(el);
    }
    else
    {
	    node <T> *temp = head;
	    for(int i=0; i<loc-2; i++)
	    {
	     	temp = temp -> next;
	    }
	    newNode->next = temp->next;
	    temp->next = newNode;
	    newNode->prev = temp;
	}
}

template <class T> void Dlist<T> :: add_tail(T el)
{
	if(tail != NULL)
	{
		tail = new node<T>(el,tail,NULL);
		tail -> prev -> next = tail;
	}
	else
	{
		head = tail = new node<T>(el);
	}
}

template <class T> T Dlist<T> :: delete_head()
{
	T el = head -> info;
	node <T> *temp = head;
	if(head == tail)
	{
		head = tail = NULL;
	}
	else
	{
		head = head -> next;
		head -> prev = NULL;
	}
	delete temp;
	return el;
}

template <class T> void Dlist<T> :: delete_loc(int loc)
{
    if(loc == 0)
    {
        delete_head();
    }
    else
    {
	    node <T> *temp = head;
	    node <T> *n = head -> next;
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

template <class T> T Dlist <T> :: delete_tail()
{
	T el = tail -> info;
	if(head == tail)
	{
		delete head;
		head = tail = NULL;
	}
	else
	{
		tail = tail -> prev;
		delete tail -> next;
		tail -> next = NULL;
	}
	return el;
}

template <class T> bool Dlist <T> :: search(T el)
{
	node<T> *temp;
	for(temp = head ; temp != NULL && !(temp -> info == el); temp = temp -> next)
	               ;
	if(temp != NULL)
	return true;
	else
	return false;
}

template <class T> void Dlist <T> :: concat(Dlist<T> &obj, Dlist<T> &obj2)
{
	node <T> *p;
	p = obj.head;
	while(p -> next != NULL)
	{
		p = p -> next;
	}
	p -> next = obj2.head;
	
	display();
}

template <class T> void Dlist<T> :: delete_node(T el)
{
	if(head != NULL)
	{
		if(head == tail && el == tail -> info)
		{
			delete head;
			head = tail = NULL;
		}
		else if(el == head -> info)
		{
			node <T> *temp = head;
			head = head -> next;
			head -> prev = NULL;
			delete temp;
		}
		else
	    {
		    node <T> *temp;
		    for(temp = head -> next; temp != NULL && !(temp -> info == el); temp = temp -> next);
			if(temp != NULL)
			{
				if(temp == tail)
				{
					tail = tail -> prev;
					tail -> next = NULL;
				}
				else
				{
					temp -> prev -> next = temp -> next;
					temp -> next -> prev = temp -> prev;
				}
				delete temp;
			}
		}
	}
}

template <class T> void Dlist <T> :: display()
{
	node<T> *temp;
	for(temp = head; temp != NULL ; temp = temp -> next)
	{
		cout<< temp -> info<< " ";
	}
}

template <class T> void Dlist <T> :: reverse()
{
	if(isempty() || head == tail)
	{
		return;
	}
	node<T> *curr = head;
	node<T> *temp = NULL;
	while(curr != NULL){
		temp = curr -> prev;
		curr -> prev = curr -> next;
		curr -> next = temp;
		curr = curr -> prev;
	}
	head = temp -> prev;
}

template <class T> int Dlist <T> :: count()
{
	node<T> *temp;
	int count = 0;
	for(temp = head; temp != NULL ; temp = temp -> next)
	{
		count = count + 1;
	}
	return count;
}

int main()
{
	cout<<"* --------------------------------- MENU --------------------------------- *"<<endl;
	cout<<"*   01) Insert an element at the beginning of the linked list.             *"<<endl;
	cout<<"*   02) Insert an element at the specific location in the linked list.     *"<<endl;
	cout<<"*   03) Insert an element at the end of the linked list.                   *"<<endl;
	cout<<"*   04) Remove an element from the beginning of the linked list.           *"<<endl;
	cout<<"*   05) Remove an element from the specific location in the linked list.   *"<<endl;
	cout<<"*   06) Remove an element from the end of the linked list.                 *"<<endl;
	cout<<"*   07) Search for an element.                                             *"<<endl;
	cout<<"*   08) Concatenate two linked lists.                                      *"<<endl;
	cout<<"*   09) Remove an element with a specific value.                           *"<<endl;
	cout<<"*   10) Display the linked list.                                           *"<<endl;    
	cout<<"*   11) Reverse the linked list.                                           *"<<endl;     
	cout<<"*   12) Count the number of elements in the linked list.                   *"<<endl;
	cout<<"* ------------------------------------------------------------------------ *"<<endl;
	cout<<endl;
	
	Dlist<int> obj,obj2,obj3;
	int k;
	int val,loc;
	//values for second linked-list
	obj2.add_head(5);
	obj2.add_head(9);
	obj2.add_head(1);
	obj2.add_tail(10);
	
	do{
		cout<<"Enter choice: "<<endl;
		cin>>k;
		switch(k){
			case 0:{cout<<"Program terminated.";
				    break;
			}
			case 1:{cout<<"Enter an element to add on head: ";
			        cin>>val;
			        obj.add_head(val);
			        cout<<endl;
				    break;
			}
			case 2:{cout<<"Enter an element to add: ";
			        cin>>val;
			        cout<<"Enter the location: ";
			        cin>>loc;
			        obj.add(loc, val);
			        cout<<endl;
				    break;
			}
			case 3:{cout<<"Enter an element to add on tail: ";
			        cin>>val;
			        obj.add_tail(val);
			        cout<<endl;
				    break;
			}
			case 4:{cout<<"Delete an element from head. ";
			        cout<<endl;
			        obj.delete_head();
			        cout<<endl;
				    break;
			}
			case 5:{cout<<"Enter the location: ";
			        cin>>loc;
			        obj.delete_loc(loc);
				    break;
			}
			case 6:{cout<<"Delete an element from tail. ";
			        cout<<endl;
			        obj.delete_tail();
			        cout<<endl;
				    break;
			}
			case 7:{cout<<"Search for an element: ";
			        cin>>val;
			        bool result = obj.search(val);
			        if(result == true){
			        	cout<<"Element is in the linked list."<<endl;
					}
					else{
						cout<<"Element is not in the linked list."<<endl;
					}
				    break;
			}
			case 8:{cout<<"New linked list is: ";
					obj.concat(obj, obj2);
					cout<<endl;
		   			break;
			}
			case 9:{cout<<"Enter an element which you want to delete: ";
			        cin>>val;
			    	obj.delete_node(val);
			    	cout<<endl;
			    	cout<<"After deleting the specific element the linked list is: ";
			    	obj.display();
			    	cout<<endl;
				    break;
			}
			case 10:{cout<<"First doubly linked list is: ";
			        obj.display();
			        cout<<endl;
			        cout<<"Second doubly linked list is: ";
			        obj2.display();
				    cout<<endl;
				     break;
			}
			case 11:{obj.reverse();
			         obj2.reverse();
			         cout<<"Press *10* to see the result.";
			         cout<<endl;
				     break;
			}
			case 12:{cout<<"Number of elements in the linked list are: "<<obj.count();
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
