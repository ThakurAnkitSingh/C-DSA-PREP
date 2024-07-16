#include<iostream>
using namespace std;

void bubbleSort(int* arr, int n)
{   
    for(int i=1; i<n; i++){
        bool swapped = false;
        for(int j=0; j<n-i; j++){
            if(arr[j] > arr[j+1]){
                swapped = true;
                swap(arr[j], arr[j+1]);
            }
        }
        if(!swapped) break;
    }
    for(int i=0; i<n; i++){
    cout << arr[i] << " " << endl;
    }
}

int main(){
    int arr[5] = {5,2,4,1,3};
    bubbleSort(arr, 5);
}


// Time Complexity = O(n^2);
// Best case = O(n)
// It is going from n-1 to 1 steps and sum of all these steps is n(n-1)/2 which is equal to n^2-n/2 = n^2
// Space Complexity = O(1);
// Shifting largest to the right side