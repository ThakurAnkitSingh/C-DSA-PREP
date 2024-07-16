#include <bits/stdc++.h>
using namespace std;

void subsets(vector<int> arr, int n, int idx, vector<vector<int>> result, vector<int> temp)
{
    if (idx >= n)
    {
        result.push_back(temp);
        return;
    }

    subsets(arr, n, idx + 1, result, temp);

    // we have to first include the subsets and exclude it
    temp.push_back(arr[idx]);
    // we are including the sets
    subsets(arr, n, idx + 1, result, temp);
}

int main()
{
    vector<vector<int>> result;
    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    int idx = 0;
    vector<int> temp;
    subsets(arr, n, idx, result, temp);

    // for (int i = 0; i < result.size(); i++)
    // {
    //     cout << "{ ";
    //     for (int j = 0; j < result[i].size(); j++)
    //     {
    //         cout << result[i][j] << " ";
    //     }
    //     cout << "} " << endl;
    // }
    return 0;
}