/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).

Example 1:

Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3
Explanation: Choose the last item that weighs 1 unit and holds a value of 3.
Example 2:

Input:
N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).
Your Task:
Complete the function knapSack() which takes maximum capacity W, weight array wt[], value array val[], and the number of items n as a parameter and returns the maximum possible value you can get.

Expected Time Complexity: O(N*W).
Expected Auxiliary Space: O(N*W)

Constraints:
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ v[i] ≤ 1000


*/

// Recursive approach

// int knapSack(int W, int wt[], int val[], int n)
// {
//     // Your code here
//     // if 0 items are present or capacity of bag is 0
//     if (n == 0 || W == 0)
//     {
//         return 0;
//     }

//     if (wt[n - 1] <= W)
//     {
//         return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
//     }

//     else if(wt[n - 1] > W){
//         return knapSack(W, wt, val, n - 1);
//     }
// }

// Recursion + Memoization

// int solve(int W, int wt[], int val[], int n, vector<vector<int>> &dp)
// {
//     // if 0 items are present or capacity of bag is 0
//     if (n == 0 || W == 0)
//     {
//         return 0;
//     }

//     if (dp[n][W] != -1)
//     {
//         return dp[n][W];
//     }

//     int ans;

//     if (wt[n - 1] <= W)
//     {
//         ans = max(val[n - 1] + solve(W - wt[n - 1], wt, val, n - 1, dp), solve(W, wt, val, n - 1, dp));
//     }

//     else if (wt[n - 1] > W)
//     {
//         ans = solve(W, wt, val, n - 1, dp);
//     }

//     dp[n][W] = ans;
//     return ans;
// }

// int knapSack(int W, int wt[], int val[], int n)
// {
//     // Your code here
//     vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
//     return solve(W, wt, val, n, dp);
// }

// Tabulation

// int knapSack(int W, int wt[], int val[], int n)
// {
//     // Your code here
//     vector<vector<int>> dp(n + 1, vector<int>(W + 1));

//     for(int j = 0; j <= W; j++){
//         dp[0][j] = 0;
//     }

//     for(int i = 0; i <= n; i++){
//         dp[i][0] = 0;
//     }

//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= W; j++){
//             if(wt[i - 1] <= j){
//                 dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
//             }
//             else if(wt[i - 1] > j){
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }

//     return dp[n][W];
// }

// time complexity :- O(N * W)
// space complexity :- O(N * W)