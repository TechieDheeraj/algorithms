/**
 *      file    :  1143_LongestCommonSubsequence.cpp
 *      author  :  techiedheeraj
 *      created :  2020 Dec 15 23:53:26
 *      lastMod :  Tue Dec 15 23:53:26 2020
 **/

class Solution {
public:
    int dp[1001][1001];
  /*
    int lcs(string& s1, string& s2, int n1, int n2) {
      if (n1 == 0 || n2 == 0) return 0;

      if (dp[n1][n2] != -1) return dp[n1][n2];
      if (s1[n1-1] == s2[n2-1])
        return dp[n1][n2] = 1+lcs(s1, s2, n1-1, n2-1);
      else
        return dp[n1][n2] = max(lcs(s1, s2, n1, n2-1), lcs(s1, s2, n1-1, n2));
    }
   */
    int lcs(string &s1, string& s2, int n1, int n2) {
      for (int i = 0; i < n1+1; ++i) {
        for (int j = 0; j < n2+1; ++j) {
          if (i == 0 || j == 0) {
            dp[i][j] = 0;
            continue;
          }

          if (s1[i-1] == s2[j-1])
            dp[i][j] = 1+dp[i-1][j-1];
          else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
      }
      return dp[n1][n2];
    }
    int longestCommonSubsequence(string& text1, string& text2) {
      //memset(dp, 0, sizeof(dp));
      //memset(dp, -1, sizeof(dp));
      return lcs(text1, text2, text1.length(), text2.length());
    }
};
