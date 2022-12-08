// 5. Write a program to implement circularly linked list which supports the following operations:
// (i) Insert an element x at the front of the circularly linked list
// (ii) Insert an element x after an element y in the circularly linked list
// (iii)Insert an element x at the back of the circularly linked list
// (iv) Remove an element from the back of the circularly linked list
// (v) Remove an element from the front of the circularly linked list
// (vi) Remove the element x from the circularly linked list
// (vii)Search for an element x in the circularly linked list and return its pointer
// (viii) Concatenate two circularly linked lists

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Practical5
{
private:
    Node *head;

public:
    Node *flag = new Node();
    Practical5()
    {
        head = NULL;
    }

    void insertAtBeginning(int newElement)
    {
        Node *newNode = new Node();
        newNode->data = newElement;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    void insertAtEnd(int newElement)
    {
        Node *newNode = new Node();
        newNode->data = newElement;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }
    void insertAfterElement(int elementX, int elementY)
    {
        Node *result = search(elementY);
        if (result == flag)
        {
            cout << "Element " << elementX << " cannot be inserted as Element " << elementY << " is not found in the list" << endl;
        }
        else
        {
            Node *elemX = new Node();
            elemX->data = elementX;
            elemX->next = NULL;

            if (result->next == head)
            {
                result->next = elemX;
                elemX->next = head;
            }
            else
            {
                elemX->next = result->next;
                result->next = elemX;
            }
        }
    }
    void insertAtPosition(int newElement, int position)
    {
        Node *newNode = new Node();
        newNode->data = newElement;
        newNode->next = NULL;
        Node *temp = head;
        int NoOfElements = 0;

        if (temp != NULL)
        {
            NoOfElements++;
            temp = temp->next;
        }
        while (temp != head)
        {
            NoOfElements++;
            temp = temp->next;
        }

        if (position < 1 || position > (NoOfElements + 1))
        {
            cout << "\nInvalid position.";
        }
        else if (position == 1)
        {

            if (head == NULL)
            {
                head = newNode;
                head->next = head;
            }
            else
            {
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                newNode->next = head;
                head = newNode;
                temp->next = head;
            }
        }
        else
        {
            temp = head;
            for (int i = 1; i < position - 1; i++)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void deleteAtBeginning()
    {
        if (head != NULL)
        {
            if (head->next == head)
            {
                head = NULL;
            }
            else
            {
                Node *temp = head;
                Node *firstNode = head;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                head = head->next;
                temp->next = head;
                free(firstNode);
            }
        }
    }
    void deleteAtPosition(int position)
    {
        Node *nodeToDelete = head;
        Node *temp = head;
        int NoOfElements = 0;

        if (temp != NULL)
        {
            NoOfElements++;
            temp = temp->next;
        }
        while (temp != head)
        {
            NoOfElements++;
            temp = temp->next;
        }

        if (position < 1 || position > NoOfElements)
        {
            cout << "\nInavalid position.";
        }
        else if (position == 1)
        {
            if (head->next == head)
            {
                head = NULL;
            }
            else
            {
                while (temp->next != head)
                    temp = temp->next;
                head = head->next;
                temp->next = head;
                free(nodeToDelete);
            }
        }
        else
        {

            temp = head;
            for (int i = 1; i < position - 1; i++)
                temp = temp->next;
            nodeToDelete = temp->next;
            temp->next = temp->next->next;
            free(nodeToDelete);
        }
    }
    void deleteAtEnd()
    {
        if (head != NULL)
        {
            if (head->next == head)
            {
                head = NULL;
            }
            else
            {
                Node *temp = head;
                while (temp->next->next != head)
                    temp = temp->next;
                Node *lastNode = temp->next;
                temp->next = head;
                free(lastNode);
            }
        }
    }
    void deleteElement(int x)
    {
        Node *result = search(x);
        if (result == flag)
        {
            cout << "Element " << x << " is not found in the list" << endl;
        }
        else
        {

            if (head == result)
            {
                Node *temp = result;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                if (head == head->next)
                {
                    head = NULL;
                }
                else
                {
                    head = result->next;
                    temp->next = head;
                }

                free(result);
            }
            else
            {
                Node *temp = head;
                while (temp->next != result)
                {
                    temp = temp->next;
                }
                if (result->next != head)
                {
                    temp->next = result->next;
                    free(result);
                }
                else
                {
                    temp->next = head;
                    free(result);
                }
            }
        }
    }
    Node *search(int x)
    {
        Node *temp = head;
        int pos = -1;
        if (temp != NULL)
        {
            while (true)
            {
                pos++;
                if (temp->data == x)
                {
                    flag->data = pos;
                    return temp;
                }
                temp = temp->next;
                if (temp == head)
                {
                    break;
                }
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

            Node *newNode = new Node();
            newNode->data = elem;
            newNode->next = NULL;
            if (h == NULL)
            {
                h = newNode;
                newNode->next = h;
            }
            else
            {
                Node *temp = h;
                while (temp->next != h)
                {
                    temp = temp->next;
                }

                temp->next = newNode;
                newNode->next = h;
            }

            cout << "To continue... Enter 1 (To exit : Enter any integer(only) except 1) : ";
            cin >> run;
            // if (run != 1)
            // {
            //     break;
            // }
        } while (run == 1);

        return h;
    }
    Node *concatenate(Node *node1, Node *node2)
    {
        Node *temp = node1;
        while (temp->next != node1)
        {
            temp = temp->next;
        }
        temp->next = node2;

        Node *temp2 = node2;
        while (temp2->next != node2)
        {
            temp2 = temp2->next;
        }
        temp2->next = node1;

        return node1;
    }

    // Function overloading
    void printList(Node *list)
    {

        Node *temp = list;
        if (temp != NULL)
        {
            cout << "The list contains: ";
            while (true)
            {
                cout << temp->data << " ";
                temp = temp->next;
                if (temp == list)
                    break;
            }
            cout << endl;
        }
        else
        {
            cout << "The list is empty.\n";
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
    void printList()
    {
        Node *temp = head;
        if (temp != NULL)
        {
            cout << "The list contains: ";
            while (true)
            {
                cout << temp->data << " ";
                temp = temp->next;
                if (temp == head)
                    break;
            }
            cout << endl;
        }
        else
        {
            cout << "The list is empty.\n";
        }
    }
};
int main()
{

    Practical5 LinkedList;
    int choice;
    cout << "\nEnter your choice" << endl;
    do
    {
        cout << "1 - Insert an element x at the beginning of the circular linked list" << endl;
        cout << "2 - Insert an element x after an element y in the circular linked list" << endl;
        cout << "3 - Insert an element x at the end of the circular linked list" << endl;
        cout << "4 - Remove an element from the beginning of the circular linked list" << endl;
        cout << "5 - Remove an element from the end of the circular linked list." << endl;
        cout << "6 - Remove an element x from the circular linked list." << endl;
        cout << "7 - Search for an element x in the circular linked list and return its pointer" << endl;
        cout << "8 - Concatenate two circular linked lists" << endl;
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
            int elemX, elemY;
            cout << "Enter elementX : ";
            cin >> elemX;
            cout << "Enter elementY : ";
            cin >> elemY;
            LinkedList.insertAfterElement(elemX, elemY);
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
            LinkedList.deleteAtEnd();
            cout << "Updated list : ";
            LinkedList.printList();
            break;
        }
        case 6:
        {
            int x;
            cout << "Enter element x : ";
            cin >> x;
            LinkedList.deleteElement(x);
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