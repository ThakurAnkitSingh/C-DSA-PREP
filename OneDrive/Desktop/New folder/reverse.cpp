#include <iostream>
using namespace std;

int* reverseFn(int arr[], int n)
{
    int i=0;
    int j=n-1;
    while(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    // cout << "Array " << arr << endl;
    return arr;
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
    int* result = reverseFn(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    cout << "Reversed Array : " << result << endl;
}