#include <iostream> // cin, cout

using namespace std;

int tmp[500001];
int target;
int memo = 1;
int result = -1;

void merge(int a[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 1;

    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
        {
            tmp[k++] = a[i++];
        }
        else
        {
            tmp[k++] = a[j++];
        }
    }
    while (i <= mid)
        tmp[k++] = a[i++];
    while (j <= right)
        tmp[k++] = a[j++];

    for (int q = left, k = 1; q <= right; q++, k++, memo++)
    {
        a[q] = tmp[k];
        if (memo == target)
        {
            result = a[q];
        }
    }
}

void merge_sort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}

int main()
{
    int n;
    cin >> n >> target;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    merge_sort(a, 0, n - 1);

    cout << result << "\n";

    return 0;
}