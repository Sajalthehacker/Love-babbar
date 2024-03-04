/*
Given two strings, find the longest subsequence present in both of them. Both the strings are in uppercase latin alphabets.

Example 1:

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: ADH
Explanation: LCS for input strings “ABCDGH” and “AEDFHR” is “ADH” of length 3.
Example 2:

Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: AC
Explanation: LCS of "ABC" and "AC" is "AC" of length 2.
Your Task:
Complete the function lcs() which takes the length of two strings respectively and two strings as input parameters and returns the length of the longest subsequence present in both of them.

Expected Time Complexity : O(|str1|*|str2|)
Expected Auxiliary Space: O(|str1|*|str2|)

Constraints:
1<=size(str1),size(str2)<=103
*/

// Tabulation
// string printLCS(int n, int m, string s1, string s2)
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

//     string ans = "";
//     int i = n, j = m;
//     // run loop until either of the string becomes empty
//     while(i > 0 && j > 0){
//         if(s1[i - 1] == s2[j - 1]){
//             ans = ans + s1[i - 1];
//             i--;
//             j--;
//         }
//         else{
//             if(dp[i][j - 1] > dp[i - 1][j]){
//                 j--;
//             }
//             else{
//                 i--;
//             }
//         }
//     }

//     reverse(ans.begin(), ans.end());
//     return ans;
// }