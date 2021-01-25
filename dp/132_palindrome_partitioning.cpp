/**
 *      file    :  132_palindrome_partitioning.cpp 
 *      author  :  techiedheeraj
 *      created :  2021 Jan 25 19:44:28 
 *      lastMod :  Mon Jan 25 19:44:28 2021 
 **/
class Solution {
public:
    int dp[2001][2001];
    bool isPalindrome(string& s, int i, int j) {
      string tmp = s.substr(i, j-i+1);
      string rev = tmp;
      reverse(rev.begin(), rev.end());
      if (rev == tmp) return true;
      else return false;
    }

    int partition(string& s, int i, int j) {
      if (i >= j) return 0;

      if (isPalindrome(s, i, j)) return 0;
      if (dp[i][j] != -1) return dp[i][j];

      int res = INT_MAX;

      for (int k=i; k < j; ++k) {
        int left = 0;
        int right = 0;
        int tmp = 0;

        if (dp[i][k] != -1)
          left = dp[i][k];
        else
          left = partition(s, i, k);
        if (dp[k+1][j] != -1)
          right = dp[k+1][j];
        else
          right = partition(s, k+1, j);
        tmp = 1+left+right;
        res = min(res, tmp);
      }
      return dp[i][j] = res;
    }
    int minCut(string& s) {
      memset(dp, -1, sizeof(dp));

      return partition(s, 0, s.length()-1);
    }
};
