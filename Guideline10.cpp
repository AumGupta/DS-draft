//10. Implement Double-ended Queues using Linked list representation 

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

class Deque
{

public:
    Node *front;
    Node *rear;
    int size;
    Deque()
    {
        front = rear = NULL;
        size = 0;
    }
    Node *getnode(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->prev = newNode->next = NULL;
        return newNode;
    }

    bool isEmpty()
    {
        return (front == NULL);
    }

    int dequeSize()
    {
        return size;
    }

    void insertFront(int data)
    {
        Node *newNode = getnode(data);
        if (newNode == NULL)
        {
            cout << "OverFlow" << endl;
        }
        else
        {
            if (front == NULL)
            {
                rear = front = newNode;
            }

            else
            {
                newNode->next = front;
                front->prev = newNode;
                front = newNode;
            }
            size++;
        }
    }

    void insertRear(int data)
    {
        Node *newNode = getnode(data);
        if (newNode == NULL)
        {
            cout << "OverFlow" << endl;
        }
        else
        {
            if (rear == NULL)
            {
                front = rear = newNode;
            }
            else
            {
                newNode->prev = rear;
                rear->next = newNode;
                rear = newNode;
            }
            size++;
        }
    }

    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "UnderFlow" << endl;
        }

        else
        {
            Node *temp = front;
            front = front->next;

            if (front == NULL)
            {
                rear = NULL;
            }
            else
            {
                front->prev = NULL;
            }
            free(temp);

            size--;
        }
    }

    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "UnderFlow" << endl;
        }
        else
        {
            Node *temp = rear;
            rear = rear->prev;

            if (rear == NULL)
            {
                front = NULL;
            }
            else
            {
                rear->next = NULL;
            }
            free(temp);
            size--;
        }
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return front->data;
    }

    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return rear->data;
    }

    void displayDeque()
    {
        if (isEmpty())
        {
            cout << "Deque : ";
            cout << "The deque is Empty\n";
        }
        else
        {
            cout << "Deque : ";
            Node *ptr = front;
            while (ptr != NULL)
            {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Deque dq;
    int choice, elem;

    do
    {
        cout << "\n1 - Insert element at FRONT" << endl;
        cout << "2 - Insert element at REAR" << endl;
        cout << "3 - Delete element at FRONT" << endl;
        cout << "4 - Delete element at REAR" << endl;
        cout << "5 - Show element at FRONT" << endl;
        cout << "6 - Show element at REAR" << endl;
        cout << "7 - Size of Deque" << endl;
        cout << "8 - Display Deque" << endl;
        cout << "9 - Exit" << endl;

        cout << "\nEnter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter element to be inserted at FRONT end of Deque : ";
            cin >> elem;
            dq.insertFront(elem);
            cout << "Inserted at FRONT : " << elem << endl;
            dq.displayDeque();
            break;
        }
        case 2:
        {
            cout << "Enter element to be inserted at REAR end of Deque : ";
            cin >> elem;
            dq.insertRear(elem);
            cout << "Inserted at REAR : " << elem << endl;
            dq.displayDeque();
            break;
        }
        case 3:
        {

            dq.deleteFront();
            cout << "Deleted from FRONT : " << elem << endl;
            dq.displayDeque();
            break;
        }
        case 4:
        {
            dq.deleteRear();
            cout << "Deleted from REAR : " << elem << endl;
            dq.displayDeque();
            break;
        }
        case 5:
        {
            cout << "Element at FRONT : " << dq.getFront() << endl;
            break;
        }
        case 6:
        {
            cout << "Element at REAR : " << dq.getRear() << endl;
            break;
        }
        case 7:
        {
            cout << "Size of Deque : " << dq.dequeSize() << endl;
            break;
        }
        case 8:
        {
            dq.displayDeque();
            break;
        }
        case 9:
        {
            cout << "Exiting...!" << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice!" << endl;
            break;
        }
        }

    } while (choice != 9);
    return 0;
}