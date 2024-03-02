/*
https://www.geeksforgeeks.org/problems/coin-change2448/1

Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ].
Note: Assume that you have an infinite supply of each type of coin. And you can use any coin as many times as you want.

Example 1:

Input:
N = 3, sum = 4
coins = {1,2,3}
Output: 4
Explanation: Four Possible ways are: {1,1,1,1},{1,1,2},{2,2},{1,3}.
Example 2:

Input:
N = 4, Sum = 10
coins = {2,5,3,6}
Output: 5
Explanation: Five Possible ways are: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.
Your Task:
You don't need to read input or print anything. Your task is to complete the function count() which accepts an array coins its size N and sum as input parameters and returns the number of ways to make change for given sum of money.

Expected Time Complexity: O(sum*N)
Expected Auxiliary Space: O(sum)

Constraints:
1 <= sum, N, coins[i] <= 103


*/

// Recursive
// long long int count(int coins[], int N, int sum)
// {
//     // code here.
//     if(sum == 0){
//         return 1;
//     }
//     if(N == 0){
//         return 0;
//     }

//     if(coins[N - 1] <= sum){
//         return count(coins, N, sum - coins[N - 1]) + count(coins, N - 1, sum);
//     }

//     else{
//         return count(coins, N - 1, sum);
//     }
// }

// Recursion + memoization 

// long long int solve(int coins[], int N, int sum, vector<vector<long long int> > &dp){
//     if(sum == 0){
//         dp[N][sum] = 1;
//         return 1;
//     }
//     if(N == 0){
//         dp[N][sum] = 0;
//         return 0;
//     }

//     if(dp[N][sum] != -1){
//         return dp[N][sum];
//     }

//     if(coins[N - 1] <= sum){
//         dp[N][sum] = solve(coins, N, sum - coins[N - 1], dp) + solve(coins, N - 1, sum, dp);
//     }

//     else{
//         dp[N][sum] = solve(coins, N - 1, sum, dp);
//     }

//     return dp[N][sum];
// }

// long long int count(int coins[], int N, int sum)
// {
//     // code here.
//     vector<vector<long long int> > dp(N + 1, vector<long long int> (sum + 1, -1));
//     return solve(coins, N, sum, dp);
// }

// Tabulation
// long long int count(int coins[], int N, int sum)
// {
//     // code here.
//     vector<vector<long long int> > dp(N + 1, vector<long long int> (sum + 1, -1));
    
//     for(int i = 0; i <= N; i++){
//         dp[i][0] = 1;
//     }

//     for(int j = 1; j <= sum; j++){
//         dp[0][j] = 0;
//     }

//     for(int i = 1; i <= N; i++){
//         for(int j = 1; j <= sum; j++){
//             if(coins[i - 1] <= j){
//                 dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
//             }
//             else{
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }

//     return dp[N][sum];
// }
