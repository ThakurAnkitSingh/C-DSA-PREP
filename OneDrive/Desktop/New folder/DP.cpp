// // Dynamic Programming Series

// /*
// Problem statement
// Ninja has given a fence, and he gave a task to paint this fence. The fence has 'N' posts, and Ninja has 'K' colors. Ninja wants to paint the fence so that not more than two adjacent posts have the same color.

// Ninja wonders how many ways are there to do the above task, so he asked for your help.

// Your task is to find the number of ways Ninja can paint the fence. Print the answer modulo 10^9 + 7.

// Example:
// Input: 'N' = 3, 'K' = 2
// Output: 6

// Say we have the colors with the numbers 1 and 0. We can paint the fence with 3 posts with the following different combinations.

// 110
// 001
// 101
// 100
// 010
// 011
// */

// // Solving through Recursion Approach

// #include <bits/stdc++.h>
// #define MOD 1000000007

// int add(int a, int b)
// {
//     return ((a % MOD) + (b % MOD)) % MOD;
// }

// int mul(int a, int b)
// {
//     return ((a % MOD) * 1LL * (b % MOD)) % MOD;
// }

// int solve(int n, int k)
// {
//     if (n == 1)
//         return k;
//     if (n == 2)
//         return add(k, mul(k, k - 1));

//     int ans = add(mul(solve(n - 2, k), k - 1), mul(solve(n - 1, k), k - 1));
//     return ans;
// }
// int solveMemo(int n, int k, vector<int> &dp)
// {
//     if (n == 1)
//         return k;
//     if (n == 2)
//         return add(k, mul(k, k - 1));
//     if (dp[n - 1] != -1)
//         return dp[n];

//     dp[n] = add(mul(solveMemo(n - 2, k, dp), k - 1), mul(solveMemo(n - 1, k, dp), k - 1));
//     return dp[n];
// }

// int solveTab(int n, int k)
// {
//     vector<int> dp(n + 1, 0);
//     dp[1] = k;
//     dp[2] = add(k, mul(k, k - 1));

//     for (int i = 3; i <= n; i++)
//     {
//         dp[i] = add(mul(dp[i - 2], k - 1), mul(dp[i - 1], k - 1));
//     }
//     return dp[n];
// }

// int solveSpace(int n, int k)
// {
//     int p1 = k;
//     int p2 = add(k, mul(k, k - 1));

//     for (int i = 3; i <= n; i++)
//     {
//         int curr = add(mul(p1, k - 1), mul(p2, k - 1));
//         p1 = p2;
//         p2 = curr;
//     }
//     return p2;
// }

// int numberOfWays(int n, int k)
// {
//     return solveSpace(n, k);
// }

// /*
// 0 1 Knapsack Problem Medium (5 approaches)

// You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
// In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).
// */

// int solve(int wt[], int val[], int capacity, int idx)
// {
//     if (idx == 0)
//     {
//         if (wt[0] <= capacity)
//             return val[0];
//         else
//             return 0;
//     }

//     // Inclusion
//     int incl = 0;

//     if (wt[idx] <= capacity)
//     {
//         incl = val[idx] + solve(wt, val, capacity - wt[idx], idx - 1);
//     }

//     int excl = 0 + solve(wt, val, capacity - wt[idx], idx - 1);

//     return max(incl, excl);
// }

// int solveMemo(int wt[], int val[], int capacity, int idx, vector<vector<int>> &dp)
// {
//     // Base case: If there are no items left
//     if (idx == 0)
//     {
//         if (wt[0] <= capacity)
//             return val[0];
//         else
//             return 0;
//     }

//     // Return already computed value
//     if (dp[idx][capacity] != -1)
//         return dp[idx][capacity];

//     // Inclusion of the current item
//     int incl = 0;
//     if (wt[idx] <= capacity)
//     {
//         incl = val[idx] + solveMemo(wt, val, capacity - wt[idx], idx - 1, dp);
//     }

//     // Exclusion of the current item
//     int excl = solveMemo(wt, val, capacity, idx - 1, dp);

//     // Memoize the result
//     return dp[idx][capacity] = max(incl, excl);
// }

// int solveTab(int wt[], int val[], int capacity, int n)
// {
//     // Create a 2D DP array
//     vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

//     for (int i = wt[0]; i <= capacity; i++)
//     {
//         if (i <= capacity)
//             dp[0][i] = val[0];
//         else
//             dp[0][i] = 0;
//     }

//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 0; j <= capacity; j++)
//         {
//             int incl = 0;
//             if (wt[i] <= j)
//             {
//                 incl = val[i] + dp[i - 1][j - wt[i]];
//             }

//             int excl = 0 + dp[i - 1][j];

//             dp[i][j] = max(incl, excl);
//         }
//     }

//     // The last cell will have the answer
//     return dp[n - 1][capacity];
// }

// int solveSpace(int wt[], int val[], int capacity, int n)
// {
//     // Create a 2D DP array
//     vector<int> prev(capacity + 1, 0);
//     vector<int> curr(capacity + 1, 0);
//     for (int i = wt[0]; i <= capacity; i++)
//     {
//         if (i <= capacity)
//             prev[i] = val[0];
//         else
//             prev[i] = 0;
//     }

//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 0; j <= capacity; j++)
//         {
//             int incl = 0;
//             if (wt[i] <= j)
//             {
//                 incl = val[i] + prev[j - wt[i]];
//             }

//             int excl = 0 + prev[j];

//             curr[j] = max(incl, excl);
//         }
//         prev = curr;
//     }

//     // The last cell will have the answer
//     return prev[capacity];
// }

// int solveSpace2(int wt[], int val[], int capacity, int n)
// {
//     // Create a 2D DP array
//     vector<int> curr(capacity + 1, 0);
//     for (int i = wt[0]; i <= capacity; i++)
//     {
//         if (i <= capacity)
//             curr[i] = val[0];
//         else
//             curr[i] = 0;
//     }

//     for (int i = 1; i < n; i++)
//     {
//         for (int j = capacity; j >= 0; j--)
//         {
//             int incl = 0;
//             if (wt[i] <= j)
//             {
//                 incl = val[i] + curr[j - wt[i]];
//             }

//             int excl = 0 + curr[j];

//             curr[j] = max(incl, excl);
//         }
//     }

//     // The last cell will have the answer
//     return curr[capacity];
// }

// int knapSack(int W, int wt[], int val[], int n)
// {
//     return solveSpace2(wt, val, W, n);
// }



// /*
// Combinational Sum 4

// Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

// The test cases are generated so that the answer can fit in a 32-bit integer.

// */

// class Solution {
// public:
//     int solve(vector<int>& nums, int x) {
//         if (x == 0)
//             return 1;
//         if (x < 0)
//             return 0;

//         int ans = 0;

//         for (int i = 0; i < nums.size(); i++) {
//             ans += solve(nums, x - nums[i]);
//         }
//         return ans;
//     }
//     int solveMemo(vector<int>& nums, int x, vector<int>&dp) {
//         if (x == 0)
//             return 1;
//         if (x < 0)
//             return 0;

//         if(dp[x] != -1) return dp[x];
//         int ans = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             ans += solveMemo(nums, x - nums[i], dp);
//         }
//         return dp[x] = ans;
//     }

//     int solveTab(vector<int>& nums, int x) {
//         vector<int >dp(x+1, 0);
//         dp[0] = 1;

//         for(int i=1; i<=x; i++){
//             for(int j=0; j<nums.size(); j++){
//                 if(i - nums[j] >= 0){
//                     dp[i] += (dp[i - nums[j]]) * 1ll;
//                 }
//             }
//         }
//         return dp[x];
//     }

//     int combinationSum4(vector<int>& nums, int target) {
//         return solveTab(nums, target);
//     }
// };