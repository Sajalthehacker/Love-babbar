/*
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
*/

// class Solution {
// public:

//     int countSubstrings(string s) {
//         int n = s.size(), ans = 0;
//         vector<vector<bool> > dp(n, vector<bool> (n, false));
        
//         for(int gap = 0; gap < n; gap++){
//             int start = 0, end = gap;
//             while(end < n){
//                 if(gap == 0){
//                     dp[start][end] = true;
//                 }
//                 else if(gap == 1){
//                     if(s[start] == s[end]){
//                         dp[start][end] = true;
//                     }
//                     else{
//                         dp[start][end] = false;
//                     }
//                 }
//                 else{
//                     if(s[start] == s[end] && dp[start + 1][end - 1] == true){
//                         dp[start][end] = true;
//                     }
//                     else{
//                         dp[start][end] = false;
//                     }
//                 }
//                 if(dp[start][end] == true){
//                     ans++;
//                 }
//                 start++;
//                 end++;
//             }
//         }

//         return ans;
//     }
// };