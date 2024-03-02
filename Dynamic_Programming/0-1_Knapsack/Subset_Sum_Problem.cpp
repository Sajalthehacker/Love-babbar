/*
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.


Example 1:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.
Example 2:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 30
Output: 0
Explanation: There is no subset with sum 30.

Your Task:
You don't need to read input or print anything. Your task is to complete the function isSubsetSum() which takes the array arr[], its size N and an integer sum as input parameters and returns boolean value true if there exists a subset with given sum and false otherwise.
The driver code itself prints 1, if returned value is true and prints 0 if returned value is false.

Expected Time Complexity: O(sum*N)
Expected Auxiliary Space: O(sum*N)

Constraints:
1 <= N <= 100
1<= arr[i] <= 100
1<= sum <= 104

*/

// recursive solution 
// bool solve(vector<int> arr, int n, int sum){
//     if(sum == 0){
//         return true;
//     }
//     else if(n == 0 || sum < 0){
//         return false;
//     }

//     if(arr[n - 1] > sum){
//         return solve(arr, n - 1, sum);
//     }
//     else if(arr[n - 1] <= sum){
//         return (solve(arr, n - 1, sum) || solve(arr, n - 1, sum - arr[n - 1]));
//     }
// }

// bool isSubsetSum(vector<int> arr, int sum)
// {
//     // code here
//     int n = arr.size();
//     return solve(arr, n, sum);
// }

// recursion + Memoization 

// bool solve(vector<int> arr, int n, int sum, vector<vector<int > > &dp){
//     if(sum == 0){
//         return true;
//     }
//     else if(n == 0 || sum < 0){
//         return false;
//     }

//     if(dp[n][sum] != -1){
//         return dp[n][sum];
//     }

//     bool ans;

//     if(arr[n - 1] > sum){
//         ans = solve(arr, n - 1, sum, dp);
//     }
//     else if(arr[n - 1] <= sum){
//         ans = (solve(arr, n - 1, sum, dp) || solve(arr, n - 1, sum - arr[n - 1], dp));
//     }
//     dp[n][sum] = ans;
//     return ans;
// }

// bool isSubsetSum(vector<int> arr, int sum)
// {
//     // code here
//     int n = arr.size();
//     vector<vector<int > > dp(n + 1, vector<int>(sum + 1, -1));
//     return solve(arr, n, sum, dp);
// }

// Tabulation 
// bool isSubsetSum(vector<int> arr, int sum)
// {
//     // code here
//     int n = arr.size();
//     vector<vector<bool > > dp(n + 1, vector<bool>(sum + 1));

//     for(int i = 0; i <= n; i++){
//         dp[i][0] = true;
//     }

//     for(int j = 1; j <= sum; j++){
//         dp[0][j] = false;
//     }

//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= sum; j++){
//             if(arr[i - 1] > j){
//                 dp[i][j] = dp[i - 1][j];
//             }
//             else{
//                 dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - arr[i - 1]]);
//             }
//         }
//     }

//     return dp[n][sum];
// }

// time complexity :- O(N * SUM)
// space complexity :- O(N * SUM)