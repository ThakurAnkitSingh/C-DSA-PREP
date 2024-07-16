#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> nums, int start, int end)
{

    // base Case
    cout << "Start : " << start << " End : " << end << endl;
    if (start == end)
    {
        // cout << "Base Cond.  start is : " << start << end << endl;
        return start;
    }
    int mid = start + (end - start) / 2;

    cout << "MId is : " << mid << endl;
    cout << " Nums element is : " << nums[mid] << "  " << nums[end] << endl;

    if (nums[mid] >= nums[end]) // e
    {
        return pivotIndex(nums, mid + 1, end);
    }
    else
    {
        return pivotIndex(nums, start, mid);
    }
}

int main()
{
    // vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    // vector<int> nums = {2, 1};
    // vector<int> nums = {11,12,13,14,15};
    // vector<int> nums = {3,3,1,3};
    vector<int>nums = {1,3,3};
    int n = nums.size();
    int start = 0;
    int end = n - 1;
    int pivotAns = pivotIndex(nums, start, end);
    cout << "Pivot Index : " << pivotAns << " -> " << nums[pivotAns] << endl;
    return pivotAns;
}
