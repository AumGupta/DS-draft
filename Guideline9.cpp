// 9. Implement Queue using Circular linked list representation

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

class Queue
{
public:
    Node *front = NULL;
    Node *rear = NULL;

    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    void enqueue(int value)
    {
        Node *ptr = new Node();
        ptr->data = value;
        ptr->link = NULL;

        if (front == NULL)
        {
            front = ptr;
            rear = ptr;
        }
        else
        {
            rear->link = ptr;
            rear = ptr;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
        }

        else
        {
            if (front == rear)
            {
                free(front);
                front = rear = NULL;
            }
            else
            {
                Node *ptr = front;
                front = front->link;
                free(ptr);
            }
        }
    }

    void showFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
        }
        else
        {
            cout << "Element at front is : " << front->data << endl;
        }
    }

    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue : ";
            cout << "The queue is empty\n";
        }
        else
        {
            cout << "Queue : ";
            Node *ptr = front;
            while (ptr != NULL)
            {
                cout << ptr->data << " ";
                ptr = ptr->link;
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue queue;
    int choice, value;
    do
    {
        cout << "1. Enqueue\n2. Dequeue\n3. Show front element\n4. Display Queue\n5. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter Value:\n";
            cin >> value;
            queue.enqueue(value);
            queue.displayQueue();
            break;
        }
        case 2:
        {
            queue.dequeue();
            queue.displayQueue();
            break;
        }
        case 3:
        {
            queue.showFront();
            break;
        }
        case 4:
        {
            queue.displayQueue();
            break;
        }
        case 5:
        {
            cout << "Exiting..." << endl;
            break;
        }
        default:
        {
            cout << "Invlid choice" << endl;
            break;
        }
        }
    } while (choice != 5);

    return 0;
}