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

int main(){
	//char str[] = {'6','2','3','+','-','3','8','2','/','+','*','2','^','3','+'};
	//char str[] = {'5','3','-','6','+','8','2','/','1','2','+','-','*'};
	//char str[] = {'2','1','+','3','*'};
	//char str[] = {'4','3','2','5','*','-','+'};
	char str[80];
	cout<<"Enter you expression: ";
	cin>>str;
	ArrayStack<double> e;
	int op1, op2;
	int result;
	char c;
	for(int i=0; (c=str[i]) != '\0'; i++){
		if(c >='0' && c <='9'){
			e.push(int(c-'0'));
		}
		else{
			op2 = e.top();
			e.pop();
			op1 = e.top();
			e.pop();
			
		switch(c){
		case '+': e.push(op1+op2);
		break;
		case '-': e.push(op1-op2);
		break;
		case '*': e.push(op1*op2);
		break;
		case '/': e.push(op1/op2);
		break;
		case '^': e.push(pow(op1,op2));
		break;
		default : cout<<"Your expresion have some invalid symbol.";
		break;
    	    }
		}
	}
	cout<<"Result is: "<<e.top();
	return 0;
}
