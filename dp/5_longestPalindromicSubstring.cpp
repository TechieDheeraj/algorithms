/**
 *      file    :  5_longestPalindromicSubstring.cpp
 *      author  :  techiedheeraj
 *      created :  2021 Jan 16 20:25:27
 *      lastMod :  Sat Jan 16 20:25:27 2021
 **/

/* Note: 

For example, 

S = "caba", rev(s)  = "abac".

The longest common substring between both is : "aba", which is the answer.

Let’s try another example: 
S = "abacdfgdcaba", rev(s) = "abacdgfdcaba".

The longest common substring between both is:  "abacd". Clearly, this is not a valid palindrome.

Algorithm

We could see that the longest common substring method fails when there exists a reversed copy of a non-palindromic substring in some other part of S. To rectify this, each time we find a longest common substring candidate, we check if the substring’s indices are the same as the reversed substring’s original indices. If it is, then we attempt to update the longest palindrome found so far; if not, we skip this and find the next candidate.
*/

class Solution {
public:
    int dp[1001][1001];
  
    string lcs(string& s1, string& s2, int n1, int n2) {
      int res = INT_MIN;
      string ans;
      
      for (int i = 0; i < n1+1; ++i) {
        for (int j = 0; j < n2+1; ++j) {
          if (i == 0 || j == 0) {
            dp[i][j]= 0;
            continue;
          }
          if (s1[i-1] == s2[j-1]) {
            dp[i][j] = 1+dp[i-1][j-1]; 
            if (res < dp[i][j]) {
              string temp = s1.substr(i-dp[i][j], dp[i][j]);
              string revtemp = temp;
              reverse(revtemp.begin(), revtemp.end());
              if (temp == revtemp) {
                res = dp[i][j];
                ans = temp;
              }
            }
          }
          else
            dp[i][j] = 0;
        }
      }
      return ans;
    }
    string longestPalindrome(string s) {
      string rev = s;
      reverse(rev.begin(), rev.end());
      
      return lcs(s, rev, s.length(), rev.length());
    }
};
