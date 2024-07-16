#include <iostream>
using namespace std;

void swap(int arr[], int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void sort01(int arr[], int n)
{
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        if (arr[i] == 1)
        {
            swap(arr, i, j);
            j--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    cout << "Enter the Elements" << endl;
    int arr[100];
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort01(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " " << endl;
    }
}