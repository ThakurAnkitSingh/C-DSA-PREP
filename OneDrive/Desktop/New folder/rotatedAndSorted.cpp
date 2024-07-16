#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int nums[5] = {3, 4, 5, 1, 2};

    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            count++;
            cout << "Count in For loop " << count << endl;
        }
    }
    if (nums[n - 1] > nums[0])
    {
        count++;
        cout << "Count in Condition " << count << endl;
    }
    if (count > 1)
    {
        return false;
    }
    return true;
}
