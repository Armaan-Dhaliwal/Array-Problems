/*
Chapter TEST
Problem Statement: Maximum Profit on App
Problem Level: MEDIUM
Problem Description:
You have made a smartphone app and want to set its price such that the profit earned is maximised. There are certain buyers who will buy your app only if their budget is greater than or equal to your price.
You will be provided with a list of size N having budgets of buyers and you need to return the maximum profit that you can earn.
Lets say you decide that price of your app is Rs. x and there are N number of buyers. So maximum profit you can earn is :
 m * x

where m is total number of buyers whose budget is greater than or equal to x.
Input format :
Line 1 : N (No. of buyers)
Line 2 : Budget of buyers (separated by space)

Output Format :
 Maximum profit

Constraints :
1 <= N <= 10^6

Sample Input 1 :
4
30 20 53 14

Sample Output 1 :
60

Sample Output 1 Explanation :
Price of your app should be Rs. 20 or Rs. 30. For both prices, you can get the profit Rs. 60.
Sample Input 2 :
5
34 78 90 15 67

Sample Output 2 :
201

Sample Output 2 Explanation :
Price of your app should be Rs. 67. You can get the profit Rs. 201 (i.e. 3 * 67).*/

#include <iostream>
using namespace std;

void Merge(int a[], int si, int mid, int ei)
{
    int n1 = mid - si + 1;
    int t1[n1];
    int n2 = ei - mid;
    int t2[n2];
    int r = 0;
    for (int i = si; i <= mid; i++)
    {
        t1[r] = a[i];
        r++;
    }

    int q = 0;
    for (int i = mid + 1; i <= ei; i++)
    {
        t2[q] = a[i];
        q++;
    }

    int i = 0;
    int j = 0;
    int k = si;
    while (i < n1 || j < n2)
    {
        if (i < n1 && j < n2)
        {
            if (t1[i] <= t2[j])
            {
                a[k] = t1[i];
                i++;
                k++;
            }
        }
        if (i < n1 && j < n2)
        {
            if (t2[j] <= t1[i])
            {
                a[k] = t2[j];
                j++;
                k++;
            }
        }

        if (i < n1 && j >= n2)
        {
            a[k] = t1[i];
            i++;
            k++;
        }
        if (j < n2 && i >= n1)
        {
            a[k] = t2[j];
            j++;
            k++;
        }
    }
}

void MergeSort(int a[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }

    int mid = (si + ei) / 2;
    MergeSort(a, si, mid);
    MergeSort(a, (mid + 1), ei);
    Merge(a, si, mid, ei);
}

int Find_Min(int arr[], int N, int m)
{
    int min = 10000;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] < min && arr[i] > m)
        {
            min = arr[i];
        }
    }

    return min;
}

int Count(int arr[], int min, int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] >= min)
        {
            count++;
        }
    }

    return count;
}

int Find_Max(int arr[], int N)
{
    int max = -10000;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

int main()
{
    int N;
    cout << "Give number of parties: " << endl;
    cin >> N;

    int Budgets[N];
    int Profits[N];

    for (int i = 0; i < N; i++)
    {
        cin >> Budgets[i];
    }

    MergeSort(Budgets, 0, N);
    cout << "Your sorted array" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << Budgets[i] << "\t";
    }
    cout << endl;

    int m = 0;
    for (int i = 0; i < N; i++)
    {
        int min = Find_Min(Budgets, N, m);
        int count = Count(Budgets, min, N);
        Profits[i] = count * min;
        m = min;
    }

    cout << "Your Profits: " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << Profits[i] << "\t" << endl;
    }

    cout << "Required answer:" << endl;
    cout << Find_Max(Profits, N) << endl;
}