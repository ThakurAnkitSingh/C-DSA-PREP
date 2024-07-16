#include<iostream>
using namespace std;

void selectionSort(int* arr, int n)
{   
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    for(int i=0; i<n; i++){
    cout << arr[i] << " " << endl;
    }
}

int main(){
    int arr[5] = {5,2,4,1,3};
    selectionSort(arr, 5);
}


// Time Complexity = O(n^2);
// Best Case Complexity = O(n^2);
// It is going from n-1 to 1 steps and sum of all these steps is n(n-1)/2 which is equal to n^2-n/2 = n^2
// Space Complexity = O(1);
// Shifting smallest to the left side