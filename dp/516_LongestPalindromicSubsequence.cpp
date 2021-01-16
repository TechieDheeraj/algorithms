/**
 *      file    :  516_LongestPalindromicSubsequence.cpp
 *      author  :  techiedheeraj
 *      created :  2020 Dec 17 23:10:57
 *      lastMod :  Thu Dec 17 23:10:57 2020
 **/

class Solution {
public:
    int dp[1001][1001];
    int lcs(string& s1, string& s2, int n1, int n2) {
      for (int i= 0; i < n1+1; ++i) {
        for (int j= 0; j < n2+1; ++j) {
          if (i == 0 || j == 0) {
            dp[i][j] = 0; continue;
          }
          if (s1[i-1] == s2[j-1])
            dp[i][j] = 1+dp[i-1][j-1];
          else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
      }
      int len = dp[n1][n2];
      string res;
      
      while(n1 != 0 && n2 != 0) {
        if (s1[n1-1] == s2[n2-1]) {
          res.push_back(s1[n1-1]); 
          --n1; --n2;
        }
        else {
          dp[n1-1][n2] > dp[n1][n2-1] ? --n1 : --n2;
        }
      }
      return len == res.length() ? len : 0;
    }
    int longestPalindromeSubseq(string s) {
      string rev = s;
      reverse(rev.begin(), rev.end());
      return lcs(s, rev, s.length(), rev.length());
    }
};


/*
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
*/
