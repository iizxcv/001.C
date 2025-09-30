#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(int arr[])
{
    for (int i = 1; i < sizeof(arr) / sizeof(int); i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 and arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    insertion_sort(a);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}