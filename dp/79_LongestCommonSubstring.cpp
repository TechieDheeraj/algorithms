/**
 *      file    :  79_LongestCommonSubstring.cpp
 *      author  :  techiedheeraj
 *      created :  2021 Jan 15 02:28:54
 *      lastMod :  Fri Jan 15 02:28:54 2021
 **/

class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
    std::vector<vector<int>>dp;
    int lcs(string& A, string& B, int n1, int n2) {

      if (n1 == 0 || n2 == 0) return 0;
      int res = INT_MIN;
      for (int i =0; i < n1+1; ++i ) {
        for (int j =0; j < n2+1; ++j ) {
          if (i == 0 || j == 0) {
            dp[i][j] = 0;
            continue;
          }
          if (A[i-1] == B[j-1]) {
            dp[i][j] = 1+dp[i-1][j-1];
          }
          else
            dp[i][j] = 0;
          res = max(res, dp[i][j]);
        }
      }
      return res;
    }

    int longestCommonSubstring(string &A, string &B) {
        // write your code here
      dp.resize(A.length()+1, vector<int>(B.length()+1));//, -1));
      return lcs(A, B, A.length(), B.length());
    }
};
