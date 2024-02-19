/*
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation:
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explanation: This array can never be
partitioned into two such parts.
Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.

Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(sum of elements)

Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000
N*sum of elements ≤ 5*106
*/

// Recursive Solution

// int solve(int arr[], int n, int sum){
//     if(sum == 0){
//         return 1;
//     }
//     else if(n == 0 || sum < 0){
//         return 0;
//     }

//     if(arr[n - 1] > sum){
//         return solve(arr, n - 1, sum);
//     }
//     else if(arr[n - 1] <= sum){
//         if(solve(arr, n - 1, sum) == 1){
//             return 1;
//         }
//         return solve(arr, n - 1, sum - arr[n - 1]);
//     }
// }

// int equalPartition(int N, int arr[])
// {
//     // code here
//     int sum = 0;
//     for(int i = 0; i < N; i++){
//         sum = sum + arr[i];
//     }

//     if(sum % 2 != 0){
//         return 0;
//     }
//     else {
//         return solve(arr, N, sum / 2);
//     }
// }

// Recursion + Memoization
// int solve(int arr[], int n, int sum, vector<vector<int>> &dp)
// {
//     if (sum == 0)
//     {
//         return true;
//     }
//     else if (n == 0 || sum < 0)
//     {
//         return false;
//     }

//     if (dp[n][sum] != -1)
//     {
//         return dp[n][sum];
//     }

//     int ans;

//     if (arr[n - 1] > sum)
//     {
//         ans = solve(arr, n - 1, sum, dp);
//     }
//     else if (arr[n - 1] <= sum)
//     {
//         ans = (solve(arr, n - 1, sum, dp) || solve(arr, n - 1, sum - arr[n - 1], dp));
//     }
//     dp[n][sum] = ans;
//     return ans;
// }

// int equalPartition(int N, int arr[])
// {
//     // code here
//     int sum = 0;
//     for (int i = 0; i < N; i++)
//     {
//         sum = sum + arr[i];
//     }

//     if (sum % 2 != 0)
//     {
//         return 0;
//     }
//     sum = sum / 2;
//     vector<vector<int>> dp(N + 1, vector<int>(sum + 1, -1));
//     return solve(arr, N, sum, dp);
// }

// Tabulation

// int equalPartition(int N, int arr[])
// {
//     // code here
//     int sum = 0;
//     for (int i = 0; i < N; i++)
//     {
//         sum = sum + arr[i];
//     }

//     if (sum % 2 != 0)
//     {
//         return 0;
//     }

//     sum = sum / 2;
//     vector<vector<int > > dp(N + 1, vector<int>(sum + 1));

//     for(int i = 0; i <= N; i++){
//         dp[i][0] = 1;
//     }

//     for(int j = 1; j <= sum; j++){
//         dp[0][j] = 0;
//     }

//     for(int i = 1; i <= N; i++){
//         for(int j = 1; j <= sum; j++){
//             if(arr[i - 1] > j){
//                 dp[i][j] = dp[i - 1][j];
//             }
//             else{
//                 if(dp[i - 1][j] == 1){
//                     dp[i][j] = 1;
//                 }
//                 else{
//                     dp[i][j] = dp[i - 1][j - arr[i - 1]];
//                 }
//             }
//         }
//     }

//     return dp[N][sum];
// }