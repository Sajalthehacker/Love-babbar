/*
https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

Given a set of N items, each with a weight and a value, represented by the array w and val respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

Example 1:

Input:
N = 2
W = 3
val = {1, 1}
wt = {2, 1}
Output:
3
Explanation:
1.Pick the 2nd element thrice.
2.Total profit = 1 + 1 + 1 = 3. Also the total weight = 1 + 1 + 1  = 3 which is <= 3.
Example 2:

Input:
N = 4
W = 8
val[] = {6, 1, 7, 7}
wt[] = {1, 3, 4, 5}
Output:
48
Explanation:
The optimal choice is to pick the 1st element 8 times.
Your Task:
You do not need to read input or print anything. Your task is to complete the function knapSack() which takes the values N, W and the arrays val and wt as input parameters and returns the maximum possible value.

Expected Time Complexity: O(N*W)
Expected Auxiliary Space: O(W)

Constraints:
1 ≤ N, W ≤ 1000
1 ≤ val[i], wt[i] ≤ 100

*/

// recursion
// int knapSack(int N, int W, int val[], int wt[])
// {
//     // code here
//     if(W == 0 || N == 0){
//         return 0;
//     }

//     if(wt[N - 1] <= W){
//         return max(val[N - 1] + knapSack(N, W - wt[N - 1], val, wt), knapSack(N - 1, W, val, wt));
//     }
//     else{
//         return knapSack(N - 1, W, val, wt);
//     }
// }

// recursion + Memoization
// int solve(int N, int W, int val[], int wt[], vector<vector<int>> &dp)
// {
//     if (W == 0 || N == 0)
//     {
//         dp[N][W] = 0;
//         return 0;
//     }

//     if (dp[N][W] != -1)
//     {
//         return dp[N][W];
//     }

//     if (wt[N - 1] <= W)
//     {
//         dp[N][W] = max(val[N - 1] + knapSack(N, W - wt[N - 1], val, wt), knapSack(N - 1, W, val, wt));
//     }
//     else
//     {
//         dp[N][W] = knapSack(N - 1, W, val, wt);
//     }

//     return dp[N][W];
// }
// int knapSack(int N, int W, int val[], int wt[])
// {
//     // code here
//     vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
//     return solve(N, W, val, wt, dp);
// }

// Tabulation
// int knapSack(int N, int W, int val[], int wt[])
// {
//     // code here
//     vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));

//     for(int i = 0; i <= N; i++){
//         dp[i][0] = 0;
//     }
//     for(int j = 0; j <= W; j++){
//         dp[0][j] = 0;
//     }

//     for(int i = 1; i <= N; i++){
//         for(int j = 1; j <= W; j++){
//             if(wt[i - 1] <= j){
//                 dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
//             }
//             else{
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }

//     return dp[N][W];
// }