// 6. Implement a stack using Array representation
#include <iostream>
using namespace std;

class Stack
{
    int *stack; 
    int n, top;

public:
    
    Stack(int maxSize = 100)
    {
        stack = new int[maxSize];
        n = maxSize;
        top = -1;
    }
    void push(int val)
    {
        if (top >= n - 1)
            cout << "Stack Overflow" << endl;
        else
        {
            top++;
            stack[top] = val;
            cout << "Element pushed in Stack : " << val << endl;
        }
    }
    void pop()
    {
        if (top <= -1)
            cout << "Stack Underflow" << endl;
        else
        {
            cout << "Element popped from Stack : " << stack[top] << endl;
            top--;
        }
    }
    void display()
    {
        if (top >= 0)
        {
            cout << "Stack : ";
            for (int i = top; i >= 0; i--)
            {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
        else
            cout << "The Stack is empty" << endl;
    }
};

int main()
{
    Stack stack;
    int ch, val;

    do
    {
        cout << "1 - Push element into the stack" << endl;
        cout << "2 - Pop an element from the stack" << endl;
        cout << "3 - Display the stack" << endl;
        cout << "4 - Exit" << endl;

        cout << "Enter choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter the value to be pushed:" << endl;
            cin >> val;
            stack.push(val);
            stack.display();
            break;
        }
        case 2:
        {
            stack.pop();
            stack.display();
            break;
        }
        case 3:
        {
            stack.display();
            break;
        }
        case 4:
        {
            cout << "Exiting..." << endl;
            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
        }
        }
    } while (ch != 4);
    return 0;
}