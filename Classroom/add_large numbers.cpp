#include <iostream>
#include <cmath>
using namespace std;

class StackEmpty : exception{
	public:
		StackEmpty(const string& err){}
};
class StackFull : exception{
	public:
		StackFull(const string& err){}
};
template<typename E>
class ArrayStack{
	enum {DEF_CAPACITY = 100};
	public:
		ArrayStack(int cap = DEF_CAPACITY);
		int size() const;
		bool empty() const;
		const E& top() const;
		int push (const E& e);
		int pop();
		void display();
		private:
			E* S;
			int capacity;
			int t;
};

template<typename E>ArrayStack<E>::ArrayStack(int cap)
    : S(new E[cap]), capacity(cap), t(-1){}
    
template<typename E>int ArrayStack<E>::size() const
    {return (t+1);}
    
template<typename E>bool ArrayStack<E>::empty() const
    {return (t<0);}
    
template<typename E>
const E& ArrayStack<E>::top() const{
	if(empty()) throw StackEmpty("TOP OF EMPTY STACK");
	return S[t];
}

template<typename E>
int ArrayStack<E>::push(const E& e){
	if(size() == capacity) throw StackFull("PUSH TO FULL STACK");{	
	    S[++t] = e;
	    return e;
	}
	return 0;
}

template<typename E>
void ArrayStack<E>::display(){
	int A[capacity];
	for(int i=0; i<size(); i++){
		S[i];
	}
	for(int i=0; i<=size() ; i++){
		A[i] =S[i];
	}
	cout<<endl;
	cout<<"Addition of two stacks is: ";
	for(int i=size()-1; i>=0 ; i--){
		cout<<A[i];
	}
}

template<typename E>
int ArrayStack<E>::pop(){
	if(empty()) throw StackEmpty("POP FROM EMPTY STACK");
	else
	return S[t--];
}

int main(){
	ArrayStack<int> obj1,obj2,obj3;
    string n1,n2;
    cout<<"Enter the first numbers: ";
    cin>>n1;
    cout<<endl;
	cout<<"Enter the second numbers: ";
	cin>>n2;
	char c;
    for (int position = 0; position < n1.length(); position++)
    {
    	c = n1[position];
        obj1.push(int(c - '0'));
    }

    for (int position = 0; position < n2.length(); position++)
    {
    	c = n2[position];
        obj2.push(int(c - '0'));
    }
    int carry=0, sum=0;
    while (!obj1.empty() && !obj2.empty())
    {
        sum = (carry + obj1.top() + obj2.top());
        obj3.push(sum % 10);
        carry = sum / 10;
        obj1.pop();
        obj2.pop();
    }
    while (!obj1.empty())
    {
        sum = (carry + obj1.top());
        obj3.push(sum % 10);
        carry = sum / 10;
        obj1.pop();
    }
    while (!obj2.empty())
    {
        sum = (carry + obj2.top());
        obj3.push(sum % 10);
        carry = sum / 10;
        obj2.pop();
    }
    if (carry > 0)
    {
        obj3.push(carry);
    }

    obj3.display();
    return 0;
}
