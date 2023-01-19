#include <iostream>
using namespace std;

void Reverse(int arr[], int n)
{

    for (int i = 0; i < n / 2; i++)
    {
        int temp;
        temp = arr[n - i - 1];
        arr[n - i - 1] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int num;
    cout << "Enter number of elements in array: " << endl;
    cin >> num;
    int *arr = new int[num];

    int *temp = arr;
    int ele;
    cout << "Enter your elements: " << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> ele;
        temp[i] = ele;
    }

    cout << "Original array: " << endl;
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;

    temp = arr;
    Reverse(arr, num);

    cout << "Reversed array: " << endl;
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << "\t";
    }
}