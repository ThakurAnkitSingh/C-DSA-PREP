#include <bits/stdc++.h>
using namespace std;

void permutations(vector<int> arr, int n, int idx, vector<vector<int>> &ans)
{
    if (idx == n)
    {
        ans.push_back(arr);
        return;
    }

    for (int i = idx; i < n; i++)
    {
        swap(arr[idx], arr[i]);
        permutations(arr, n, idx + 1, ans);
        swap(arr[idx], arr[i]);
    }
}

int main()
{
    vector<int> arr = {1, 1, 2};
    int n = arr.size();
    int idx = 0;
    vector<vector<int>> ans;
    vector<vector<int>> result;
    permutations(arr, n, idx, ans);
    sort(ans.begin(), ans.end());
    auto last = unique(ans.begin(), ans.end());
    ans.erase(last, ans.end());

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << "{ ";
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << "} " << endl;
    // }
    return 0;
}