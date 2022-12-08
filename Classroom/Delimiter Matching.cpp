#include <iostream>
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
		ArrayStack(ArrayStack<E> &e);
		int size() const;
		bool empty() const;
		const E& top() const;
		int push (const E& e);
		const ArrayStack<E>& operator = (ArrayStack<E>&);
		int pop();
		~ArrayStack();
		void display();
		void clear();
		private:
			E* S;
			int capacity;
			int t;
};

template<typename E>ArrayStack<E>::ArrayStack(int cap)
    : S(new E[cap]), capacity(cap), t(-1){}
    
template<typename E>ArrayStack<E>::~ArrayStack()
{
	delete[] S;
	//cout<<"destructor called"<<endl;
}

template<typename E>ArrayStack<E>::ArrayStack(ArrayStack<E> &e)
    : S(new E[e.capacity]), capacity(e.capacity), t(-1){
		cout<<"copy constructor called : ";
	    for(int i=0; i<capacity; i++){
		    this->push(e.S[i]);
	    }
    }
    
template<typename E> const ArrayStack<E>& ArrayStack<E> :: operator = (ArrayStack<E> &e)
    {
		cout<<"Overloading assignment operator gets called "<<endl;
		cout<<"Assign all the elements of one stack to the other"<<endl;
	    for(int i=0; i<e.capacity; i++){
		    S[i] = this->push(e.S[i]);
	    }
	    display();
    }
    
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
	for(int i=0; i<size(); i++){
		cout<<S[i]<<" ";
	}
}

template<typename E>
void ArrayStack<E>::clear(){
	delete[] S;
	t = -1;
	S = new E[size()];
	cout<<"ALL ELEMENTS OF AN ARRAY GETS CLEARED."<<endl;
}

template<typename E>
int ArrayStack<E>::pop(){
	if(empty()) throw StackEmpty("POP FROM EMPTY STACK");
	else
	S[t];
	return --t;
}

bool balancecheck(string str1){
	ArrayStack<char> e;
	ArrayStack<char> s;
	
	for(int i=0; i < str1.length() ; i++){
		char c = str1[i];
		if(e.empty()){
			e.push(c);
		}
		else if ((e.top() =='(' && c == ')') || (e.top() =='{' && c == '}') || (e.top() =='[' && c == ']')){
			e.pop();
		}
		else{
			e.push(c);
		}
	}
	
    if(e.empty()){
	    return true;
    }
        return false;
}

int main(){
	string str1;
	cout<<"Enter the string (Pair of only brackets): ";
	cin>>str1;
	
    if (balancecheck(str1) == true ){
    	cout<<"valid brackets.";
	}
	else{
		cout<<"Invalid brackets.";
	}
	return 0;
}
