#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int s, int e)
{
    cout << "start " << s << "end " << e << endl;
    int pivot = arr[e];
    int i = s;
    int end = s;
    while (i < e)
    {
        if (arr[i] <= pivot)  // {1, 6, 9, 7, 8, 5, 4, 2, 3}
        {
            swap(arr[end], arr[i]);
            // cout << "end " << arr[end] << " i " << arr[i] << endl;
            // cout << "end " << end << " i " << i << endl;
            end++;
        }
        i++;
    }
    swap(arr[end], arr[e]);

    cout << " Partition Function " << end << endl;

    // for (int i = 0; i <= e; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    return end;
}

void quickSort(vector<int>& arr, int s, int e)
{
    if (s >= e)
        return;

    // first do partition

    int pivotIdx = partition(arr, s, e);
    cout << "Pivot Index : " << pivotIdx << endl;

    // Sort the left partition

    quickSort(arr, s, pivotIdx - 1);

    // // Sort the right partition
    quickSort(arr, pivotIdx+1, e);
}

int main()
{
    vector<int> arr = {1, 6, 9, 7, 8, 5, 4, 2, 3, 11, 40, 22, 31, 70, 3, 3, 3};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }

    return 0;
}

// Average and Best Case Time Complexity O(nlogn) and worst Case O(N^2);