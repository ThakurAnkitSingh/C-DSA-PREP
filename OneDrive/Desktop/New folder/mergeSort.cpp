#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int mid, int e)
{
    int leftStart = s, rightStart = mid + 1;
    int leftEnd = mid, rightEnd = e;

    vector<int> leftArr;
    vector<int> rightArr;

    // Put the values of  arr[x] to the left array and the right array
    // int x = 0, y = 0;
    for (int i = leftStart; i <= leftEnd; i++)
    {
        // leftArr[x++] = arr[i];
        leftArr.push_back(arr[i]);
    }

    for (int i = rightStart; i <= rightEnd; i++)
    {
        // leftArr[y++] = arr[i];
        rightArr.push_back(arr[i]);
    }

    // cout << "LEFT ARRAYS " << leftArr << endl;
    // cout << "RIGHT ARRAYS " << rightArr << endl;

    // Now we have two sorted arrays and we have to merge them in the original array

    int k = s;
    int idx1 = 0;
    int idx2 = 0;

    while (idx1 < leftArr.size() && idx2 < rightArr.size())
    {
        if (leftArr[idx1] <= rightArr[idx2])
        {
            arr[k++] = leftArr[idx1++];
        }
        else
        {
            arr[k++] = rightArr[idx2++];
        }
    }

    while (idx1 < leftArr.size())
    {
        arr[k++] = leftArr[idx1++];
    }
    while (idx2 < rightArr.size())
    {
        arr[k++] = rightArr[idx2++];
    }
}

void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        // Base Case
        return;
    }
    // First sort the left part

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);

    // then Sort the right part

    mergeSort(arr, mid + 1, e);

    // Merge 2 sorted both arrays
    merge(arr, s, mid, e);
}

int main()
{
    int arr[] = {5, 3, 6, 4, 1, 2};
    int n = 6;

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

// O(nlogn) Time and O(n) Space Complexity