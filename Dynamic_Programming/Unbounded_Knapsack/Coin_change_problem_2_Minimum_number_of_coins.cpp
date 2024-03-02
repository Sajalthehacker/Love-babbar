/*
https://www.geeksforgeeks.org/problems/number-of-coins1824/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article


Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then return -1.


Example 1:

Input: V = 30, M = 3, coins[] = {25, 10, 5}
Output: 2
Explanation: Use one 25 cent coin
and one 5 cent coin
Example 2:
Input: V = 11, M = 4,coins[] = {9, 6, 5, 1}
Output: 2
Explanation: Use one 6 cent coin
and one 5 cent coin

Your Task:
You don't need to read input or print anything. Complete the function minCoins() which takes V, M and array coins as input parameters and returns the answer.

Expected Time Complexity: O(V*M)
Expected Auxiliary Space: O(V)

Constraints:
1 ≤ V*M ≤ 106
All array elements are distinct

*/

// recursion
// int solve(vector<int> &coins, int N, int sum)
// {
//     if (sum == 0)
//     {
//         return 0;
//     }

//     if (N == 0)
//     {
//         return INT_MAX - 1;
//     }

//     if (coins[N - 1] <= sum)
//     {
//         return min(1 + solve(coins, N, sum - coins[N - 1]), solve(coins, N - 1, sum));
//     }
//     else
//     {
//         return solve(coins, N - 1, sum);
//     }
// }
// int minCoins(vector<int> &coins, int M, int V)
// {
//     // Your code goes here
//     int ans = solve(coins, M, V);
//     if (ans >= INT_MAX - 1)
//     {
//         return -1;
//     }
//     return ans;
// }

// recursion + memoization
// int solve(vector<int> &coins, int N, int sum, vector<vector<int> > &dp)
// {
//     if (sum == 0)
//     {
//         dp[N][sum] = 0;
//         return 0;
//     }

//     if (N == 0)
//     {
//         dp[N][sum] = INT_MAX - 1;
//         return INT_MAX - 1;
//     }

//     if(dp[N][sum] != -1){
//         return dp[N][sum];
//     }

//     if (coins[N - 1] <= sum)
//     {
//         dp[N][sum] = min(1 + solve(coins, N, sum - coins[N - 1], dp), solve(coins, N - 1, sum, dp));
//     }
//     else
//     {
//         dp[N][sum] = solve(coins, N - 1, sum, dp);
//     }

//     return dp[N][sum];
// }
// int minCoins(vector<int> &coins, int M, int V)
// {
//     // Your code goes here
//     vector<vector<int> > dp(M + 1, vector<int>(V + 1, - 1));
//     int ans = solve(coins, M, V, dp);
//     if (ans >= INT_MAX - 1)
//     {
//         return -1;
//     }
//     return ans;
// }

// Tabulation
// int minCoins(vector<int> &coins, int M, int V)
// {
//     // Your code goes here
//     vector<vector<int> > dp(M + 1, vector<int>(V + 1, - 1));
//     for(int j = 0; j <= V; j++){
//         dp[0][j] = INT_MAX - 1;
//     }

//     for(int i = 1; i <= M; i++){
//         dp[i][0] = 0;
//     }

//     for(int i = 1; i <= M; i++){
//         for(int j = 1; j <= V; j++){
//             if(coins[i - 1] <= j){
//                 dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
//             }
//             else{
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }

//     if(dp[M][V] == INT_MAX - 1){
//         return -1;
//     }
//     return dp[M][V];
// }