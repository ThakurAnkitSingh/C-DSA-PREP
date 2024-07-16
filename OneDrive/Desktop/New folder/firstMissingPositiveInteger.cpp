#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= 0)
            nums[i] = n + 1;

        cout << nums[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
        if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0)
        {
            nums[abs(nums[i]) - 1] *= -1;
        }
        // cout << nums[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            return i + 1;
        }
        cout << nums[i] << " ";
    }
    return n + 1;
}

int firstMissingPositives(vector<int> &nums)
{
    // It will work for both negative and positive numbers
    const int n = nums.size();
    for (int i = 0; i < n; ++i)
        while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            swap(nums[i], nums[nums[i] - 1]);

    for (int i = 0; i < n; ++i)
        if (nums[i] != i + 1)
            return i + 1;

    return n + 1;
}

int main()
{
    vector<int> nums = {3, -4, 5, 6, 7, 1, 2};
    int result = firstMissingPositive(nums);
    cout << "RESULT : " << result << endl;
    return 0;
}