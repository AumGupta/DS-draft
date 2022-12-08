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
	for(int i=0; i<size(); i++){
		cout<<S[i]<<" ";
	}
}

template<typename E>
int ArrayStack<E>::pop(){
	if(empty()) throw StackEmpty("POP FROM EMPTY STACK");
	else
	return S[t--];
}

int prec(char c){
	if(c == '^'){
		return 3;
	}
	else if(c == '/' || c == '*'){
		return 2;
	}
	else if(c == '+' || c == '-'){
		return 1;
	}
	else{
		return -1;
	}
}
int main(){
	string str1;
	cout<<"Enter the string: ";
	cin>>str1;
	cout<<endl;
	ArrayStack<char> e;
	string str2;
	
	for(int i=0; i < str1.length() ; i++){
		char c = str1[i];
		if((c >='a' && c <='z')||(c >='A' && c <='Z')||(c >='0' && c <='9')){
			str2 += c;
		}
		else if(c == '('){
			e.push(c);
		}
		else if(c == ')'){
			while((e.top() != '(') && (!e.empty())){
				str2 += e.top();
				e.pop();
			}
			e.pop();
		}
		else{
			while( (!e.empty()) && prec(c) <= prec(e.top())){
		        str2 += e.top();
		        e.pop();
	        }
		    e.push(str1[i]);
		}
	}
    while(!e.empty()){
    	str2 += e.top();
    	e.pop();
	}
    cout<<"Infix expression into postfix expression: "<<str2;
    return 0;
}
