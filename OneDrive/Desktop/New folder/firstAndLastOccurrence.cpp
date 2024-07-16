#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int> &arr, int target, int start, int end)
{
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (arr[mid] == target)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int lastOccurrence(vector<int> &arr, int target, int start, int end)
{
    int ans = -1;
    if (start == end)
        return ans;
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
        ans = mid;
        return lastOccurrence(arr, target, mid + 1, end);
    }
    else if (arr[mid] > target)
    {
        end = lastOccurrence(arr, target, start, mid - 1);
    }
    else
    {
        return lastOccurrence(arr, target, mid + 1, end);
    }
}

vector<int> occurrence(vector<int> &nums, int target)
{
    vector<int> result;
    if (!nums.size())
    {
        return {-1, -1};
    }
    int start = 0;
    int end = nums.size() - 1;
    int first = firstOccurrence(nums, target, start, end);
    int last = lastOccurrence(nums, target, start, end);
    result.push_back(first);
    result.push_back(last);
    return result;
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result;
    if (!nums.size())
    {
        cout << -1 << -1 << endl;
        return 0;
    }
    int start = 0;
    int end = nums.size() - 1;
    int first = firstOccurrence(nums, target, start, end);
    int last = lastOccurrence(nums, target, start, end);
    result.push_back(first);
    result.push_back(last);
    // cout << "Result " << result << endl;
    return 0;
}