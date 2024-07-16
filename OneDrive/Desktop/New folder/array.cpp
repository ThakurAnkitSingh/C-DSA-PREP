#include <iostream>
using namespace std;

int reverseFn(int arr[], int n)
{
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
        sum += arr[j];
    }
    return sum;
}

int main()
{
    cout << "Please Enter the size and There elements" << endl;
    int size;
    int arr[100];
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int totalSum = reverseFn(arr, size);
    cout << "Tota sum of all the elements is : " << totalSum << endl;
}