// 7. Implement a stack using Linked representation

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *head;

public:
    Stack()
    {
        head = NULL;
    }

    void push(int elem)
    {
        Node *node = new Node();
        node->data = elem;
        node->next = NULL;

        cout << "Element pushed in stack : " << elem << endl;

        if (head == NULL)
        {
            head = node;
        }
        else
        {
            node->next = head;
            head = node;
        }
        print();
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "Underflow";
        }
        else
        {
            Node *temp = head;
            head = temp->next;

            cout << "Element popped from stack : " << temp->data << endl;
            free(temp);
        }
        print();
    }
    int top()
    {
        return head->data;
    }

    void print()
    {
        if (head != NULL)
        {
            Node *temp = head;
            cout << "Stack : ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "The list is Empty" << endl;
        }
    }
};

int main()
{
    Stack stack;
    int ch;
    do
    {
        cout << "1 - Push element into the stack" << endl;
        cout << "2 - Pop element from the stack" << endl;
        cout << "3 - Find element at top of stack" << endl;
        cout << "4 - Print stack" << endl;
        cout << "5 - Exit the program" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int elem;
            cout << "Enter an element" << endl;
            cin >> elem;
            stack.push(elem);
            break;
        }
        case 2:
        {
            stack.pop();
            break;
        }
        case 3:
        {
            cout << "Element at the top of stack : " << stack.top() << endl;
            break;
        }
        case 4:
        {
            stack.print();
            break;
        }
        case 5:
        {
            cout << "Exiting..." << endl;
            break;
        }
        }

    } while (ch != 5);
    return 0;
}