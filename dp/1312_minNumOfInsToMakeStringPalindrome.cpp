/**
 *      file    :  1312_minNumOfInsToMakeStringPalindrome.cpp
 *      author  :  techiedheeraj
 *      created :  2021 Jan 17 13:31:19
 *      lastMod :  Sun Jan 17 13:31:19 2021
 **/

class Solution {
public:
    int dp[501][501];
    int lps(string& s1, string& s2, int n1, int n2) {
      for (int i=0; i < n1+1; ++i) {
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
      int len = dp[n1][n2];
      string ans;
      
      while (n1 != 0 && n2 != 0) {
        if (s1[n1-1] == s2[n2-1]) {
          ans.push_back(s1[n1-1]);
          --n1;
          --n2;
        }
        else {
          if (dp[n1-1][n2] > dp[n1][n2-1])
            --n1; 
          else
            --n2;
        }
      }
      reverse(ans.begin(), ans.end());
      return ans.length() == len ? len : 0;
    }
    int minInsertions(string s) {
      string rev = s;
      reverse(rev.begin(), rev.end()); 
      return s.length()-lps(s, rev, s.length(), rev.length());
    }
};
