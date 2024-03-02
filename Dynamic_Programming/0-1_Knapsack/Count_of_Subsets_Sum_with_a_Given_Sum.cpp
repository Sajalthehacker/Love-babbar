/*
watch video solution at 
https://youtu.be/PM_ay02NzlQ?si=3pctVrV1mynKyh8x

Given an array arr of non-negative integers(including zero as well) and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

Note: Answer can be very large, so, output answer modulo 109+7.

Example 1:

Input:
N = 6
arr = [5, 2, 3, 10, 6, 8]
sum = 10
Output:
3
Explanation:
{5, 2, 3}, {2, 8}, {10} are possible subsets.
Example 2:
Input:
N = 5
arr = [2, 5, 1, 4, 3]
sum = 10
Output:
3
Explanation:
{2, 1, 4, 3}, {5, 1, 4}, {2, 5, 3} are possible subsets.
Your Task:
You don't need to read input or print anything. Complete the function perfectSum() which takes N, array arr and sum as input parameters and returns an integer value.

Expected Time Complexity: O(N*sum)
Expected Auxiliary Space: O(N*sum)

Constraints:
1 ≤ N*sum ≤ 106
0 ≤ arr[i] ≤ 106
*/

// Recursion
// int mod = 1e9 + 7;
// int perfectSum(int arr[], int n, int sum)
// {
//     // Your code goes here
//     if(n == 0 && sum == 0){
//         return 1;
//     }
//     else if(n == 0 && sum > 0){
//         return 0;
//     }

//     if(arr[n - 1] <= sum){
//         return (perfectSum(arr, n - 1, sum - arr[n - 1]) + perfectSum(arr, n - 1, sum)) % mod;
//     }
//     else{
//         return perfectSum(arr, n - 1, sum) % mod;
//     }
// }

// recursion + memoization
// int mod = 1e9 + 7;
// int solve(int arr[], int n, int sum, vector<vector<int> > &dp){
//     if(n == 0 && sum == 0){
//         dp[n][sum] = 1;
//         return 1;
//     }
//     else if(n == 0 && sum > 0){
//         dp[n][sum] = 0;
//         return 0;
//     }

//     if(dp[n][sum] != -1){
//         return dp[n][sum];
//     }

//     if(arr[n - 1] <= sum){
//         return dp[n][sum] = (perfectSum(arr, n - 1, sum - arr[n - 1]) + perfectSum(arr, n - 1, sum)) % mod;
//     }
//     else{
//         return dp[n][sum] = perfectSum(arr, n - 1, sum) % mod;
//     }
// }
// int perfectSum(int arr[], int n, int sum)
// {
//     // Your code goes here
//     vector<vector<int> > dp(n + 1, vector<int> (sum + 1, -1));
//     return solve(arr, n, sum, dp);
// }

// Tabulation
// int mod = 1e9 + 7;
// int perfectSum(int arr[], int n, int sum)
// {
//     // Your code goes here
//     vector<vector<int> > dp(n + 1, vector<int> (sum + 1, -1));
//     dp[0][0] = 1;
//     for(int j = 1; j <= sum; j++){
//         dp[0][j] = 0;
//     }

//     for(int i = 1; i <= n; i++){
//         for(int j = 0; j <= sum; j++){
//             if(arr[i - 1] <= j){
//                 dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % mod;
//             }
//             else if(arr[i - 1] > j){
//                 dp[i][j] = dp[i - 1][j] % mod;
//             }
//         }
//     }

//     return dp[n][sum];
// }

// note if there are only positive integers in array (exclusing 0) then in above question only base condition changes 

