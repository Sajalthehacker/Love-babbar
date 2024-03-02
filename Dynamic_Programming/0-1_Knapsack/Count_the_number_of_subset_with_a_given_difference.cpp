/*
https://youtu.be/ot_XBHyqpFc?si=6EsMt9CIc2N8ns0R

Given an array arr, partition it into two subsets(possibly empty) such that their union is the original array. Let the sum of the element of these two subsets be S1 and S2.

Given a difference d, count the number of partitions in which the difference of S1 and S2 is equal to d. since the answer may be large return it modulo 109 + 7.

Example 1:

Input:
n = 4, d = 3
arr[] =  { 5, 2, 6, 4}
Output:
1
Explanation:
There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.
Example 2:

Input:
n = 4, d = 0 arr[] = {1, 1, 1, 1} Output: 6
Your Task:
You don't have to read input or print anything. Your task is to complete the function countPartitions() which takes the integer n and d and array arr and returns the count of partitions.

Constraint:
1 <= n <= 500
0 <= d  <= 2500
0 <= arr[i] <= 50

Expected Time Complexity: O( N * MAX_SUM), where N and MAX_SUM denote the number of elements in the array and the maximum possible sum of array elements.
Expected Space Complexity: O( N * MAX_SUM), where N and MAX_SUM denote the number of elements in the array and the maximum possible sum of array elements.

*/

// Recursion

// int mod = 1e9 + 7;
// int perfectSum(vector<int> arr, int n, int sum)
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

// int countPartitions(int n, int d, vector<int> &arr)
// {
//     // Code here
//     int sum = 0;
//     for(int i = 0; i < n; i++){
//         sum = sum + arr[i];
//     }

//     sum = (sum + d) / 2;

//     return perfectSum(arr, n, sum);
// }

// recursion + memoization
// int mod = 1e9 + 7;
// int solve(vector<int> arr, int n, int sum, vector<vector<int> > &dp){
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
// int perfectSum(vector<int> arr, int n, int sum)
// {
//     // Your code goes here
//     vector<vector<int> > dp(n + 1, vector<int> (sum + 1, -1));
//     return solve(arr, n, sum, dp);
// }

// int countPartitions(int n, int d, vector<int> &arr)
// {
//     // Code here
//     int sum = 0;
//     for(int i = 0; i < n; i++){
//         sum = sum + arr[i];
//     }

//     sum = (sum + d) / 2;

//     return perfectSum(arr, n, sum);
// }

// Tabulation
// int mod = 1e9 + 7;
// int perfectSum(vector<int> arr, int n, int sum)
// {
//     // Your code goes here
//     vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
//     dp[0][0] = 1;
//     for (int j = 1; j <= sum; j++)
//     {
//         dp[0][j] = 0;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 0; j <= sum; j++)
//         {
//             if (arr[i - 1] <= j)
//             {
//                 dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % mod;
//             }
//             else if (arr[i - 1] > j)
//             {
//                 dp[i][j] = dp[i - 1][j] % mod;
//             }
//         }
//     }

//     return dp[n][sum];
// }

// int countPartitions(int n, int d, vector<int> &arr)
// {
//     // Code here
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         sum = sum + arr[i];
//     }

//     sum = (sum + d) / 2;

//     return perfectSum(arr, n, sum);
// }

/*
s1 + s2 = sum(arr)
s1 - s2 = diff
solving equation 1 and 2
s1 = (sum(arr) + diff) / 2;
now the problem is reduced to count the number of subsets with sum as s1
*/