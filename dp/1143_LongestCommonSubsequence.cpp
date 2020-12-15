/**
 *      file    :  1143_LongestCommonSubsequence.cpp
 *      author  :  techiedheeraj
 *      created :  2020 Dec 15 23:53:26
 *      lastMod :  Tue Dec 15 23:53:26 2020
 **/

class Solution {
public:
//    vector<vector<int>>dp;
    int dp[1001][1001];
    int helper(string& one, string& two, uint16_t m ,uint16_t n) {

      if (m == 0 || n == 0) return 0;
      if (dp[m][n] != -1) return dp[m][n];
      if (one[m-1] == two[n-1])  {
        dp[m][n] = 1+helper(one, two, m-1, n-1);
        return dp[m][n];
      }

      dp[m][n] = max(helper(one, two, m-1, n), helper(one, two, m, n-1));
      return dp[m][n];
    }
    int longestCommonSubsequence(string& text1, string& text2) {
      uint16_t m = text1.length();
      uint16_t n = text2.length();
      memset(dp, -1, sizeof(dp));
//      dp.resize(m+1, vector<int>(n+1, -1));
      return helper(text1, text2, m, n);
    }
};
