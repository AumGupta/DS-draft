// 8. Implement Queue using Circular Array representation

#include <iostream>
using namespace std;

class Queue
{
public:
    int *arr;
    int front, rear, size;
    Queue(int arrSize = 10)
    {
        size = arrSize;
        arr = new int(size);
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    void enqueue(int value)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Queue is full \n";
        }

        else
        {
            if (front == -1)
            {
                front = 0;
            }

            rear = (rear + 1) % size;
            arr[rear] = value;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
        }
        else if (front == rear)
        {
            front = rear = -1;
        }

        else
        {
            front = (front + 1) % size;
        }
    }

    void showfront()
    {
        if (isEmpty())
            cout << "Queue is empty\n";
        else
            cout << "Element at front is : " << arr[front];
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
            int i;
            if (front <= rear)
            {
                for (i = front; i <= rear; i++)
                    cout << arr[i] << " ";
            }
            else
            {
                i = front;
                while (i < size)
                {
                    cout << arr[i] << " ";
                    i++;
                }
                i = 0;
                while (i <= rear)
                {
                    cout << arr[i] << " ";
                    i++;
                }
            }
        }
    }
};

int main()
{
    Queue queue(5);
    int choice, value;
    do
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Show front element\n4. Display Queue\n5. Exit\n";
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
            queue.showfront();
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
            cout << "Invalid choice" << endl;
            break;
        }
        }
    } while (choice != 5);

    return 0;
}