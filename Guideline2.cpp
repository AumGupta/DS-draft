/*2. Given a list of N elements, which is sorted in ascending order, you are required to search an element x
in the list. The list is stored using array data structure. If the search is successful, the output should be
the index at which the element occurs, otherwise returns -1 to indicate that the element is not present
in the list. Assume that the elements of the list are all distinct. Write a program to perform the desired
task.*/

/*Note : Since datatype of the array is not mentioned, we will create a Generic program using template function. Also, as the array is in ascending order, we will use BINARY SEARCH.*/

#include <iostream>
#include <string>
using namespace std;

template <class T>
class Practical2
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
    int BinarySearch()
    {
        T x;
        cout << "Enter element to be searched : ";
        cin >> x;

        int start = 0;
        int end = N - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (arr[mid] == x)
                return mid;
            else if (arr[mid] < x)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
};
int main()
{
    cout << "Choose datatype of the elements you wish to enter" << endl;
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
        Practical2<int> ob;
        ob.createArray();
        result = ob.BinarySearch();
        break;
    }
    case 2:
    {
        Practical2<char> ob;
        ob.createArray();
        result = ob.BinarySearch();
        break;
    }
    case 3:
    {
        Practical2<float> ob;
        ob.createArray();
        result = ob.BinarySearch();
        break;
    }
    case 4:
    {
        Practical2<double> ob;
        ob.createArray();
        result = ob.BinarySearch();
        break;
    }
    case 5:
    {
        Practical2<string> ob;
        ob.createArray();
        result = ob.BinarySearch();
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