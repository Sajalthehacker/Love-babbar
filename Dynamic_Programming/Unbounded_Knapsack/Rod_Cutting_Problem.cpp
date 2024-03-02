/*
https://www.geeksforgeeks.org/problems/rod-cutting0840/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: Consider 1-based indexing.

Example 1:

Input:
N = 8
Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output:
22
Explanation:
The maximum obtainable value is 22 by
cutting in two pieces of lengths 2 and
6, i.e., 5+17=22.
Example 2:

Input:
N=8
Price[] = {3, 5, 8, 9, 10, 17, 17, 20}
Output:
24
Explanation:
The maximum obtainable value is
24 by cutting the rod into 8 pieces
of length 1, i.e, 8*price[1]= 8*3 = 24.
Your Task:
You don't need to read input or print anything. Your task is to complete the function cutRod() which takes the array A[] and its size N as inputs and returns the maximum price obtainable.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 1000
1 ≤ Ai ≤ 105

*/

// recursion
// int solve(int len[], int price[], int n, int W){
//     if(W == 0 || n == 0){
//         return 0;
//     }

//     if(len[n - 1] <= W){
//         return max(price[n - 1] + solve(len, price, n, W - len[n - 1]), solve(len, price, n - 1, W));
//     }

//     else{
//         return solve(len, price, n - 1, W);
//     }
// }
// int cutRod(int price[], int n)
// {
//     // code here
//     int len[n];
//     for(int i = 0; i < n; i++){
//         len[i] = i + 1;
//     }
//     return solve(len, price, n, n);
// }

// recursion + memoization
// int solve(int len[], int price[], int n, int W, vector<vector<int> > &dp){
//     if(W == 0 || n == 0){
//         dp[n][W] = 0;
//         return 0;
//     }

//     if(dp[n][W] != -1){
//         return dp[n][W];
//     }

//     if(len[n - 1] <= W){
//         dp[n][W] = max(price[n - 1] + solve(len, price, n, W - len[n - 1], dp), solve(len, price, n - 1, W, dp));
//     }

//     else{
//         dp[n][W] = solve(len, price, n - 1, W, dp);
//     }

//     return dp[n][W];
// }
// int cutRod(int price[], int n)
// {
//     // code here
//     int len[n];
//     for(int i = 0; i < n; i++){
//         len[i] = i + 1;
//     }
//     vector<vector<int> > dp(n + 1, vector<int> (n + 1, -1));
//     return solve(len, price, n, n, dp);
// }

// Tabulation
// int cutRod(int price[], int n)
// {
//     // code here
//     int len[n];
//     for(int i = 0; i < n; i++){
//         len[i] = i + 1;
//     }
//     vector<vector<int> > dp(n + 1, vector<int> (n + 1, -1));
//     for(int i = 0; i <= n; i++){
//         dp[i][0] = 0;
//         dp[0][i] = 0;
//     }

//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= n; j++){
//             if(len[i - 1] <= j){
//                 dp[i][j] = max(price[i - 1] + dp[i][j - len[i - 1]], dp[i - 1][j]);
//             }
//             else{
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }

//     return dp[n][n];
// }