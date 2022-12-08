#include <iostream>

using namespace std;

template <class T>
class Polynode
{
	public:
		int coef, pow;
		Polynode *next;
		Polynode(int c, int p, Polynode<T> *ptr = NULL)
		{
			coef = c;
			pow = p;
			next = ptr;
		}
};

template <class T>
class Polynomial
{
	private:
		Polynode<T> *head, *tail;
	public:
		Polynomial(){
			head = tail = NULL;
		}
		~Polynomial();
		void get_Polynomial(int c, int p);
		void display();
		T add(Polynomial &p1, Polynomial &p2);
		void add_tail(int c, int p);
};

template <class T> Polynomial<T> :: ~Polynomial()
{
	Polynode<T> *p;
	while(head == NULL)
	{
		p = head -> next;
		delete head;
		head = p;
	}
}

template <class T> void Polynomial<T> :: get_Polynomial(int c, int p)
{
	head = new Polynode<T> (c, p, head);
}

template <class T> T Polynomial<T> :: add(Polynomial &obj, Polynomial &obj2)
{
	Polynode <T> *p1, *p2;
	p1 = obj.head;
	p2 = obj2.head;
	Polynomial sum;

	while(p1 != NULL && p2!= NULL)
	{
		if(p1 -> pow == p2 -> pow)
		{
			sum.add_tail(p1 -> coef + p2 -> coef, p1 -> pow);
			p1 = p1 -> next;
			p2 = p2 -> next;
		}
		else if(p1 -> pow < p2 -> pow)
		{
			sum.add_tail(p2 -> coef, p2 -> pow);
			p2 = p2 -> next;
		}
		else
		{
			sum.add_tail(p1 -> coef, p1 -> pow);
			p1 = p1 -> next;
		}
	}
	while(p1 != NULL)
	{
		sum.add_tail(p1 -> coef, p1 -> pow);
		p1 = p1 -> next;
	}
	while(p2 != NULL)
	{
		sum.add_tail(p2 -> coef, p2 -> pow);
		p2 = p2 -> next;
	}
	sum.display();
}

template <class T> void Polynomial<T> :: add_tail(int i, int p)
{
    if (tail != NULL)
    {
        tail->next = new Polynode<T>(i, p);
        tail = tail->next;
    }

    else
        head = tail = new Polynode<T>(i, p);
}

template <class T> void Polynomial<T> :: display()
{
	Polynode<T> *temp;
	for(temp = head; temp != NULL ; temp = temp -> next)
	{
		if(temp -> next == NULL)
		{
			cout<< temp -> coef<<"x^"<<temp -> pow<<" = 0";
		}
		else
		{
			cout<< temp -> coef<<"x^"<<temp -> pow<<" + ";
		}
	}
}

int main()
{
	cout<<"* ---------------------------------- MENU ---------------------------------- *"<<endl;
	cout<<"*   01) Enter polynomial values in descending order for first polynomial.    *"<<endl;
	cout<<"*   02) Enter polynomial values in descending order for second polynomial.   *"<<endl;
	cout<<"*   03) Display the first polynomial.                                        *"<<endl;
	cout<<"*   04) Display the second polynomial.                                       *"<<endl;
	cout<<"*   05) Add two polynomials.                                                 *"<<endl;
	cout<<"* -------------------------------------------------------------------------- *"<<endl;
	cout<<endl;
	
	Polynomial<int> obj,obj2,obj3;
	int k;
	int val,pow;
	
	//obj2.get_Polynomial(5,0);
	//obj2.get_Polynomial(9,1);
	//obj2.get_Polynomial(11,2);
	
	//obj.get_Polynomial(9,0);
	//obj.get_Polynomial(-8,1);
	//obj.get_Polynomial(7,2);
	//obj.get_Polynomial(11,3);
	//obj.get_Polynomial(0,4);
	
	do{
		cout<<"Enter choice: "<<endl;
		cin>>k;
		switch(k){
			case 0:{cout<<"Program terminated.";
				    break;
			}
			case 1:{cout<<"Enter an element: ";
			        cin>>val;
			        cout<<"Enter the power: ";
			        cin>>pow;
			        obj.get_Polynomial(val,pow);
			        cout<<endl;
				    break;
			}
			case 2:{cout<<"Enter an element: ";
			        cin>>val;
			        cout<<"Enter the power: ";
			        cin>>pow;
			        obj2.get_Polynomial(val,pow);
			        cout<<endl;
				    break;
			}
			case 3:{cout<<"First Polynomial: ";
			        obj.display();
				    cout<<endl;
				    break;
			}
			case 4:{cout<<"Second Polynomial: ";
			        obj2.display();
				    cout<<endl;
				    break;
			}
			case 5:{obj.add(obj, obj2);
					cout<<endl;
					obj3.display();
				    break;
			}
			default:{cout<<"Invalid value.";
				    break;
			}
		}
	}while(k!=0);
	return 0;
}
