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
class Olist
{
	private:
		node<T> *head;
	public:
		Olist(){
			head = NULL;
		}
		~Olist();
		bool isempty();
		void insert(T el);
		void delete_node(T el);
		bool search(T el);
		void display();
	    void merge(Olist<T> &l1, Olist<T> &l2);
};

template <class T> bool Olist<T> :: isempty()
{
	return (head == NULL);
}

template <class T> Olist<T> :: ~Olist()
{
	node<T> *p;
	while(!isempty())
	{
		p = head -> next;
		delete head;
		head = p;
	}
}

template <class T> void Olist<T> :: insert(T el)
{
	node<T> *temp, *r;
	temp = head;
	r = new node<T> (el);
	if(isempty() || head -> info > el)
	{
		head = r;
		head -> next = temp;
	}
	else
	{
		while(temp -> next != NULL)
		{
			if(temp -> info <= el && (temp -> next -> info > el))
			{
				r -> next = temp -> next;
				temp -> next = r;
				return ; 
			}
			temp = temp -> next;
		}
		temp -> next = r;
		r -> next = NULL;
	}
}

template <class T> void Olist<T> :: delete_node(T el)
{
	if(head != NULL)
	{
		if(head == NULL)
		{
			delete head;
			head = NULL;
		}
		else if(el == head -> info)
		{
			node <T> *temp;
			head = head -> next;
			delete temp;
		}
		else
	    {
		    node <T> *pred, *temp;
		    for(pred = head, temp = head -> next; temp != NULL && !(temp -> info == el); pred = pred -> next, temp = temp -> next);
			if(temp != NULL)
			{
				pred -> next = temp -> next;
				delete temp;
			}
			else
			{
				return ;
			}
		}
	}
	//display();
}

template <class T> bool Olist <T> :: search(T el)
{
	node<T> *temp;
	for(temp = head ; temp != NULL && !(temp -> info == el); temp = temp -> next)
	               ;
	if(temp != NULL)
	return true;
	else
	return false;
}

template <class T> void Olist <T> :: display()
{
	node<T> *temp;
	for(temp = head; temp != NULL ; temp = temp -> next)
	{
		cout<< temp -> info<< " ";
	}
}

template <class T> void Olist <T> :: merge(Olist<T> &obj, Olist<T> &obj2)
{
	node<T> *p,*q;
	p = obj.head;
	q = obj2.head;
	Olist merge;
	
	while(p != NULL && q != NULL)
	{
		if(p -> info <= q -> info)
		{
			merge.insert(p -> info);
			p = p -> next;
		}
		else
		{
			merge.insert(q -> info);
			q = q -> next;
		}
	}
	while(q != NULL)
	{
		merge.insert(q -> info);
		q = q -> next;
	}
	while(p != NULL)
	{
		merge.insert(p -> info);
		p = p -> next;
	}
	merge.display();
}

int main()
{
	cout<<"* -------------- MENU -------------- *"<<endl;
	cout<<"*   01) Insert an element.           *"<<endl;
	cout<<"*   02) Delete an element.           *"<<endl;
	cout<<"*   03) Search for an element.       *"<<endl;
	cout<<"*   04) Display the ordered list.    *"<<endl;
	cout<<"*   05) Merge two ordered list.      *"<<endl;
	cout<<"* ---------------------------------- *"<<endl;
	cout<<endl;
	
	Olist<int> obj,obj2;
	int k;
	int val,loc;
	
	obj2.insert(5);
	obj2.insert(4);
	obj2.insert(3);
	do{
		cout<<"Enter choice: "<<endl;
		cin>>k;
		switch(k){
			case 0:{cout<<"Program terminated.";
				    break;
			}
			case 1:{cout<<"Enter an element to add on head: ";
			        cin>>val;
			        obj.insert(val);
			        cout<<endl;
				    break;
			}
			case 2:{cout<<"Enter an element which you want to delete: ";
			        cin>>val;
			    	obj.delete_node(val);
			    	cout<<endl;
			    	cout<<"After deleting the specific element the linked list is: ";
			    	obj.display();
			    	cout<<endl;
				    break;
			}
			case 3:{cout<<"Search for an element: ";
			        cin>>val;
			        bool result = obj.search(val);
			        if(result == true){
			        	cout<<"Element is in the linked list."<<endl;
					}
					else{
						cout<<"Element is not in the linked list."<<endl;
					}
					cout<<endl;
				    break;
			}
			case 4:{cout<<"Ordered linked list is : ";
					obj.display();
					cout<<endl;
				    break;
			}
			case 5:{obj.merge(obj,obj2);
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
