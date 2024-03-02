/*
Given an array arr of size n containing non-negative integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference


Example 1:

Input: N = 4, arr[] = {1, 6, 11, 5}
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12
Subset2 = {11}, sum of Subset2 = 11
Example 2:
Input: N = 2, arr[] = {1, 4}
Output: 3
Explanation:
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4

Your Task:
You don't need to read input or print anything. Complete the function minDifference() which takes N and array arr as input parameters and returns the integer value


Expected Time Complexity: O(N*|sum of array elements|)
Expected Auxiliary Space: O(N*|sum of array elements|)


Constraints:
1 ≤ N*|sum of array elements| ≤ 106
0 < arr[i] <= 105
*/

// recursion
// bool solve(int arr[], int n, int sum)
// {
//     if (sum == 0)
//     {
//         return true;
//     }
//     else if (n == 0 || sum < 0)
//     {
//         return false;
//     }

//     if (arr[n - 1] > sum)
//     {
//         return solve(arr, n - 1, sum);
//     }
//     else if (arr[n - 1] <= sum)
//     {
//         return (solve(arr, n - 1, sum) || solve(arr, n - 1, sum - arr[n - 1]));
//     }
// }

// int minDifference(int arr[], int n)
// {
//     // Your code goes here
//     int range = 0;
//     for(int i = 0; i < n; i++){
//         range = range + arr[i];
//     }

//     int ans = INT_MAX;
//     int mid = range / 2;

//     for(int i = mid; i >= 0; i--){
//         if(solve(arr, n, i)){
//             ans = min(ans, range - (2 * i));
//         }
//     }

//     return ans;
// }

// recursion + memoization
// bool solve(int arr[], int n, int sum, vector<vector<int > > &dp){
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

// int minDifference(int arr[], int n)
// {
//     // Your code goes here
//     int range = 0;
//     for(int i = 0; i < n; i++){
//         range = range + arr[i];
//     }

//     int ans = INT_MAX;
//     int mid = range / 2;

//     vector<vector<int > > dp(n + 1, vector<int>(range + 1, -1));

//     for(int i = mid; i >= 0; i--){
//         if(solve(arr, n, i)){
//             ans = min(ans, range - (2 * i));
//         }
//     }

//     return ans;
// }

// tabulation
// int minDifference(int arr[], int n)
// {
//     // Your code goes here
//     int range = 0;
//     for (int i = 0; i < n; i++)
//     {
//         range = range + arr[i];
//     }

//     int ans = INT_MAX;
//     int mid = range / 2;

//     vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));

//     for (int i = 0; i <= n; i++)
//     {
//         dp[i][0] = true;
//     }

//     for (int j = 1; j <= sum; j++)
//     {
//         dp[0][j] = false;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= sum; j++)
//         {
//             if (arr[i - 1] > j)
//             {
//                 dp[i][j] = dp[i - 1][j];
//             }
//             else
//             {
//                 dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - arr[i - 1]]);
//             }
//         }
//     }

//     for (int i = mid; i >= 0; i--)
//     {
//         if (dp[n][i])
//         {
//             ans = min(ans, range - (2 * i));
//         }
//     }

//     return ans;
// }