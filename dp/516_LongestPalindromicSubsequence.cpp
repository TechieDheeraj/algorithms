/**
 *      file    :  516_LongestPalindromicSubsequence.cpp
 *      author  :  techiedheeraj
 *      created :  2020 Dec 17 23:10:57
 *      lastMod :  Thu Dec 17 23:10:57 2020
 **/

class Solution {
public:
    vector<vector<int>>dp;
    int helper(string&s, string& sb, int l, int m) {

      if (l == 0 || m == 0) return 0;
      if (dp[l][m] != -1) return dp[l][m];

      if (s[l-1] == sb[m-1]) {
        dp[l][m] = 1+helper(s, sb, l-1, m-1);
      }
      else
        dp[l][m] = max(helper(s, sb, l-1, m), helper(s, sb, l, m-1));

      return dp[l][m];
    }
    int longestPalindromeSubseq(string s) {
      string bkpStr = s;
      int m = s.length();
      int n = s.length();
      dp.resize(m+1, vector<int>(n+1, -1));
      reverse(bkpStr.begin(), bkpStr.end());
      return helper(s, bkpStr, m, n);

//      return dp[s.length()][s.length()];
    }
};
