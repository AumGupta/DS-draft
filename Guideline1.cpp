/*1. Given a list of N elements, which follows no particular arrangement, you are required to search an
element x in the list. The list is stored using array data structure. If the search is successful, the output
should be the index at which the element occurs, otherwise returns -1 to indicate that the element is
not present in the list. Assume that the elements of the list are all distinct. Write a program to perform
the desired task.*/

/*Note : Since datatype of the array is not mentioned, we will create a Generic program using template function. Also, as no particular arrangement(ascending or descending) has been followed in the array, we will use 
LINEAR SEARCH.*/

#include <iostream>
#include <string>
using namespace std;

template <class T>
class Practical1
{
public:
    int N;
    T *arr;
    void createArray()
    {
        cout << "Enter length of array" << endl;
        cin >> N;
        arr = new T[N];

        cout << "Enter array elements... " << endl;
        for (int i = 0; i < N; i++)
        {
            cout << "Element at index " << i << " : ";
            cin >> arr[i];
        }

        cout << "Printing the array..." << endl;
        for (int i = 0; i < N; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    int LinearSearch()
    {
        T x;
        cout << "Enter element to be searched : ";
        cin >> x;

        for (int i = 0; i < N; i++)
        {
            if (arr[i] == x)
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    
    cout<<"Choose datatype of the elements you wish to enter"<<endl;
    cout << "Press 1. int" << endl;
    cout << "Press 2. char" << endl;
    cout << "Press 3. float" << endl;
    cout << "Press 4. double" << endl;
    cout << "Press 5. string" << endl;

    int ch, result;
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        Practical1<int> ob;
        ob.createArray();
        result = ob.LinearSearch();
        break;
    }
    case 2:
    {
        Practical1<char> ob;
        ob.createArray();
        result = ob.LinearSearch();
        break;
    }
    case 3:
    {
        Practical1<float> ob;
        ob.createArray();
        result = ob.LinearSearch();
        break;
    }
    case 4:
    {
        Practical1<double> ob;
        ob.createArray();
        result = ob.LinearSearch();
        break;
    }
    case 5:
    {
        Practical1<string> ob;
        ob.createArray();
        result = ob.LinearSearch();
        break;
    }
    default:
    {
        cout << "Wrong choice" << endl;
        exit(0);
    }
    }

    if (result == -1)
    {
        cout << "Element is not present in the list" << endl;
    }
    else
    {
        cout << "Element is present in the list at index " << result << endl;
    }
    return 0;
}