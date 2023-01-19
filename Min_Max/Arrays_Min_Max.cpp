#include <iostream>
#include "Pair_Class.cpp"
using namespace std;

int main()
{
    int num;
    cout << "Enter number of elements:" << endl;
    cin >> num;
    int *arr = new int[num];
    int *temp = arr;

    for (int i = 0; i < num; i++)
    {
        cin >> temp[i];
    }

    temp = arr;
    cout << "Your array:" << endl;
    for (int i = 0; i < num; i++)
    {
        cout << temp[i] << "\t";
    }
    cout << endl;

    Pair P;
    temp = arr;

    if (num == 0)
    {
        P.min = 0;
        P.max = 0;
    }

    if (num == 1)
    {
        P.min = temp[0];
        P.max = temp[0];
    }

    else if (num >= 2)
    {
        if (temp[0] < temp[1])
        {
            P.max = temp[1];
            P.min = temp[0];
        }

        else
        {
            P.max = temp[0];
            P.min = temp[1];
        }

        for (int i = 0; i < num; i++)
        {
            if (arr[i] > P.max)
            {
                P.max = temp[i];
            }

            else if (arr[i] < P.min)
            {
                P.min = temp[i];
            }
        }
    }

    cout << "Maximum is: " << P.max << endl;
    cout << "Minimum is: " << P.min << endl;
}
