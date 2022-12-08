// 4. Write a program to implement doubly linked list which supports the following operations:
// (i) Insert an element x at the beginning of the doubly linked list
// (ii) Insert an element x at position in the doubly linked list
// (iii)Insert an element x at the end of the doubly linked list
// (iv) Remove an element from the beginning of the doubly linked list
// (v) Remove an element from position in the doubly linked list.
// (vi) Remove an element from the end of the doubly linked list
// (vii) Search for an element x in the doubly linked list and return its pointer
// (viii) Concatenate two doubly linked lists

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class Practical4
{
private:
    Node *head;

public:
    Node *flag = new Node();
    Practical4()
    {
        head = NULL;
    }

    void insertAtBeginning(int newElement)
    {
        Node *newNode = new Node();
        newNode->data = newElement;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    void insertAtEnd(int newElement)
    {
        Node *newNode = new Node();
        newNode->data = newElement;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    void insertAtPosition(int newElement, int position)
    {
        Node *newNode = new Node();
        newNode->data = newElement;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (position < 1)
        {
            cout << "Position should be greater than 1" << endl;
        }
        else if (position == 1)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i < position - 1; i++)
            {
                if (temp != NULL)
                {
                    temp = temp->next;
                }
            }

            if (temp != NULL)
            {
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next = newNode;
                if (newNode->next != NULL)
                {
                    newNode->next->prev = newNode;
                }
            }
            else
            {
                cout << "The previous node is NULL" << endl;
            }
        }
    }
    void deleteAtBeginning()
    {
        if (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            free(temp);
            if (head != NULL)
            {
                head->prev = NULL;
            }
        }
    }
    void deleteAtPosition(int position)
    {
        if (position < 1)
        {
            cout << "Position should be >=1." << endl;
        }
        else if (position == 1 && head != NULL)
        {
            Node *temp = head;
            head = head->next;
            free(temp);
            if (head != NULL)
            {
                head->prev = NULL;
            }
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i < position - 1; i++)
            {
                if (temp != NULL)
                {
                    temp = temp->next;
                }
            }
            if (temp != NULL && temp->next != NULL)
            {
                Node *nodeToDelete = temp->next;
                temp->next = temp->next->next;
                if (temp->next->next != NULL)
                {
                    temp->next->next->prev = temp->next;
                }

                free(nodeToDelete);
            }
            else
            {
                cout << "The node is already full" << endl;
            }
        }
    }
    void deleteAtEnd()
    {
        if (head != NULL)
        {
            if (head->next == NULL)
            {
                head = NULL;
            }
            else
            {
                Node *temp = head;
                while (temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                Node *lastNode = temp->next;
                temp->next = NULL;
                free(lastNode);
            }
        }
    }
    Node *search(int x)
    {
        Node *temp = head;
        int pos = -1;
        if (temp != NULL)
        {
            while (temp != NULL)
            {
                pos++;
                if (temp->data == x)
                {
                    flag->data = pos;
                    return temp;
                }
                temp = temp->next;
            }
        }
        return flag;
    }
    void runSearch(int x)
    {
        Node *result = search(x);
        if (result == flag)
        {
            cout << "Element " << x << " is not found in the list" << endl;
        }
        else
        {
            cout << "Element " << x << " is found in the list at index " << flag->data << " in the list at address " << result << endl;
        }
    }

    Node *makeList()
    {
        Node *h = NULL;

        int elem;
        int run = 1;
        do
        {
            cout << "Enter element : ";
            cin >> elem;

            Node *node = new Node();
            node->data = elem;
            node->next = NULL;
            node->prev = NULL;

            if (h == NULL)
            {
                h = node;
            }
            else
            {
                Node *temp = h;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                node->prev = temp;
                temp->next = node;
            }

            cout << "To continue... Enter 1 (To exit : Enter any integer(only) except 1) : ";
            cin >> run;
            if (run != 1)
            {
                break;
            }
        } while (run == 1);
        return h;
    }
    Node *concatenate(Node *node1, Node *node2)
    {
        if (node1->next == NULL)
        {
            node1->next = node2;
            node2->prev = node1;
        }
        else
        {
            concatenate(node1->next, node2);
        }
        return node1;
    }

    // Function overloading
    void printList(Node *list)
    {
        Node *temp = list;
        if (temp != NULL)
        {
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "The linked list is EMPTY" << endl;
        }
    }
    void runConcatenate()
    {
        cout << "\nMaking new lists..." << endl;
        cout << "Enter values for List 1" << endl;
        Node *list1 = makeList();
        cout << "\nEnter values for List 2" << endl;
        Node *list2 = makeList();

        cout << "List 1 : ";
        printList(list1);

        cout << "List 2 : ";
        printList(list2);

        Node *conctenatedList = concatenate(list1, list2);

        cout << "Concatenated list : ";
        printList(conctenatedList);
    }

    // function overloading
    void printList()
    {
        Node *temp = head;
        if (temp != NULL)
        {
            cout << "The list contains : ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "The doubly linked list is EMPTY" << endl;
        }
    }
};
int main()
{

    Practical4 LinkedList;
    int choice;
    cout << "\nEnter your choice" << endl;
    do
    {
        cout << "1 - Insert an element x at the beginning of the doubly linked list" << endl;
        cout << "2 - Insert an element x at position in the doubly linked list" << endl;
        cout << "3 - Insert an element x at the end of the doubly linked list" << endl;
        cout << "4 - Remove an element from the beginning of the doubly linked list" << endl;
        cout << "5 - Remove an element from position in the doubly linked list." << endl;
        cout << "6 - Remove an element from the end of the doubly linked list." << endl;
        cout << "7 - Search for an element x in the doubly linked list and return its pointer" << endl;
        cout << "8 - Concatenate two doubly linked lists" << endl;
        cout << "9 - Print the list" << endl;
        cout << "10 - Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int elem;
            cout << "Enter an element : ";
            cin >> elem;
            LinkedList.insertAtBeginning(elem);
            cout << "Updated list : ";
            LinkedList.printList();
            break;
        }
        case 2:
        {
            int elem, pos;
            cout << "Enter an element : ";
            cin >> elem;
            cout << "Enter position at which " << elem << " is to be inserted : ";
            cin >> pos;
            LinkedList.insertAtPosition(elem, pos);
            cout << "Updated list : ";
            LinkedList.printList();
            break;
        }
        case 3:
        {
            int elem;
            cout << "Enter an element : ";
            cin >> elem;
            LinkedList.insertAtEnd(elem);
            cout << "Updated list : ";
            LinkedList.printList();
            break;
        }
        case 4:
        {
            LinkedList.deleteAtBeginning();
            cout << "Updated list : ";
            LinkedList.printList();
            break;
        }
        case 5:
        {
            int pos;
            cout << "Enter position from which element has to be deleted : ";
            cin >> pos;
            LinkedList.deleteAtPosition(pos);
            cout << "Updated list : ";
            LinkedList.printList();
            break;
        }
        case 6:
        {
            LinkedList.deleteAtEnd();
            cout << "Updated list : ";
            LinkedList.printList();
            break;
        }
        case 7:
        {
            int elem;
            cout << "Enter element to be searched : ";
            cin >> elem;
            LinkedList.runSearch(elem);
            break;
        }
        case 8:
        {
            LinkedList.runConcatenate();
            break;
        }
        case 9:
        {
            LinkedList.printList();
            break;
        }
        case 10:
        {
            cout << "Exiting..." << endl;
            break;
        }
        default:
        {
            cout << "Wrong choice...\nTry again...";
            break;
        }
        }

    } while (choice != 10);

    return 0;
}