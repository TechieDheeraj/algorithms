/**
 *      file    :  392_IsSubsequence.cpp
 *      author  :  techiedheeraj
 *      created :  2021 Jan 17 13:57:37
 *      lastMod :  Sun Jan 17 13:57:37 2021
 **/

class Solution {
public:
    vector<vector<int>>dp;
    int lcs(string& s1, string& s2, int n1, int n2) {
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
    bool isSubsequence(string s, string t) {
      dp.resize(s.length()+1, vector<int>(t.length()+1));
      int len = lcs(s, t, s.length(), t.length());
      return len == s.length();
    }
};
