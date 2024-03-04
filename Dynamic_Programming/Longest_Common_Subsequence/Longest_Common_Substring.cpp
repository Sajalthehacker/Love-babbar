/*
Given two strings. The task is to find the length of the longest common substring.


Example 1:

Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.
Example 2:

Input: S1 = "ABC", S2 "ACB", n = 3, m = 3
Output: 1
Explanation: The longest common substrings
are "A", "B", "C" all having length 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestCommonSubstr() which takes the string S1, string S2 and their length n and m as inputs and returns the length of the longest common substring in S1 and S2.


Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).


Constraints:
1<=n, m<=1000


*/

// recursion
// void solve(string S1, string S2, int n, int m, int len, int &maxLen){
//     if(n == 0 || m == 0){
//         maxLen = max(len, maxLen);
//         return;
//     }

//     if(S1[n - 1] == S2[m - 1]){
//         solve(S1, S2, n - 1, m - 1, len + 1, maxLen);
//         return;
//     }
//     else{
//         maxLen = max(maxLen, len);
//         len = 0;
//         solve(S1, S2, n - 1, m, len, maxLen);
//         solve(S1, S2, n, m - 1, len, maxLen);
//         return;
//     }
// }
// int longestCommonSubstr(string S1, string S2, int n, int m)
// {
//     // your code here
//     int len = 0, maxLen = INT_MIN;
//     solve(S1, S2, n, m, len, maxLen);
//     return maxLen;
// }

// Tabulation
// int longestCommonSubstr(string S1, string S2, int n, int m)
// {
//     // your code here
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
//     int maxLen = 0;
//     // Initialize the dp table
//     for (int i = 0; i <= n; i++)
//     {
//         dp[i][0] = 0;
//     }
//     for (int j = 0; j <= m; j++)
//     {
//         dp[0][j] = 0;
//     }
//     for (int i = 1; i <= n; ++i)
//     {
//         for (int j = 1; j <= m; ++j)
//         {
//             if (S1[i - 1] == S2[j - 1])
//             {
//                 dp[i][j] = 1 + dp[i - 1][j - 1];
//                 maxLen = max(maxLen, dp[i][j]);
//             }
//             else
//             {
//                 dp[i][j] = 0;
//             }
//         }
//     }
//     return maxLen;
// }
