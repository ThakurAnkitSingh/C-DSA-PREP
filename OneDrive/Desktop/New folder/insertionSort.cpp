#include <iostream>
using namespace std;

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " " << endl;
    }
}

int main()
{
    int arr[5] = {5, 2, 4, 1, 3};
    insertionSort(arr, 5);
}

// Time Complexity = O(n^2); 
// adaptable
// Space Complexity = O(1);
// Best case = O(n)