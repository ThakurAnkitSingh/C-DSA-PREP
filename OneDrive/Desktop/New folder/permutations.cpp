#include <bits/stdc++.h>
using namespace std;

void permutations(vector<int> arr, int n, int idx, vector<vector<int>> &ans, vector<int> temp)
{
    if (idx == n)
    {
        ans.push_back(arr);
        // cout << "{ ";

        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << "} " << endl;
        // cout << "CONDITION IDX " << idx << endl;
        // cout << "----------------------------------" << endl;
        return;
    }

    // cout << "ZEROTH IDX " << idx << " INDEX i " << endl;
    for (int i = idx; i < n; i++)
    {
        // cout << "FIRST IDX " << idx << "INDEX " << i << endl;
        swap(arr[idx], arr[i]);
        // cout << "SWAPPING PROCESS 1st " << endl;
        // cout << "{ ";
        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << "} " << endl;
        permutations(arr, n, idx + 1, ans, temp);
        // cout << "HELL----------------------------------" << endl;
        // cout << " THIRD IDX " << idx << " INDEX i " << i << endl;
        swap(arr[idx], arr[i]);
        // cout << "SWAPPING PROCESS 2st " << endl;

        // cout << "{ ";
        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << "} " << endl;
        // cout << "----------------------------------" << endl;
    }
}

int main()
{
    vector<int> arr = {1, 2, 2};
    int n = arr.size();
    int idx = 0;
    vector<vector<int>> ans;
    vector<int> temp;
    permutations(arr, n, idx, ans, temp);
    // sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "{ ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "} " << endl;
    }
    return 0;
}