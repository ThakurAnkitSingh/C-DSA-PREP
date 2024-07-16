#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int target){
    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;
    while(start <= end){
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] > target){
            end = mid-1;
        }else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int arr2[6]={1,2,3,4,5,6};

    int evenResult = binarySearch(arr2, 6, 10);
    cout << "Even Binary Search " << evenResult << endl;
    int oddResult = binarySearch(arr, 5, 2);
    cout << "Odd Binary Search " << oddResult << endl;
}