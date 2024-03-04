/*
Given two strings, find the length of longest subsequence present in both of them. Both the strings are in uppercase latin alphabets.

Example 1:

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input strings “ABCDGH” and “AEDFHR” is “ADH” of length 3.
Example 2:

Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: 2
Explanation: LCS of "ABC" and "AC" is "AC" of length 2.
Your Task:
Complete the function lcs() which takes the length of two strings respectively and two strings as input parameters and returns the length of the longest subsequence present in both of them.

Expected Time Complexity : O(|str1|*|str2|)
Expected Auxiliary Space: O(|str1|*|str2|)

Constraints:
1<=size(str1),size(str2)<=103
*/

// Recursion
// int lcs(int n, int m, string s1, string s2)
// {
//     // your code here
//     // base case 
//     if(n == 0 || m == 0){
//         return 0;
//     }

//     if(s1[n - 1] == s2[m - 1]){
//         return 1 + lcs(n - 1, m - 1, s1, s2);
//     }
//     else{
//         return max(lcs(n - 1, m, s1, s2), lcs(n, m - 1, s1, s2));
//     }
// }

// Recursion + memoization
// int solve(int n, int m, string s1, string s2, vector<vector<int>> &dp){
//     if(n == 0 || m == 0){
//         dp[n][m] = 0;
//         return 0;
//     }

//     if(dp[n][m] != -1){
//         return dp[n][m];
//     }

//     if(s1[n - 1] == s2[m - 1]){
//         dp[n][m] = 1 + solve(n - 1, m - 1, s1, s2, dp);
//     }
//     else{
//         dp[n][m] = max(solve(n - 1, m, s1, s2, dp), solve(n, m - 1, s1, s2, dp));
//     }

//     return dp[n][m];
// }
// int lcs(int n, int m, string s1, string s2)
// {
//     // your code here
//     // base case 
//     vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
//     return solve(n, m, s1, s2, dp);
// }

// Tabulation
// int lcs(int n, int m, string s1, string s2)
// {
//     // your code here
//     vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
//     for(int i = 0; i <= n; i++){
//         dp[i][0] = 0;
//     }
//     for(int j = 0; j <= m; j++){
//         dp[0][j] = 0;
//     }

//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= m; j++){
//             if(s1[i - 1] == s2[j - 1]){
//                 dp[i][j] = 1 + dp[i - 1][j - 1];
//             }
//             else{
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//     }

//     return dp[n][m];
// }