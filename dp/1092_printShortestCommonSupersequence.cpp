/**
 *      file    :  1092_printShortestCommonSupersequence.cpp
 *      author  :  techiedheeraj
 *      created :  2021 Jan 16 16:37:39
 *      lastMod :  Sat Jan 16 16:37:39 2021
 **/

class Solution {
  public:
  int lcsLen = 0;
  int dp[1001][1001];
  int lcs (string& s1, string& s2, int n1, int n2) {
    for (int i = 0; i < n1+1; ++i) {
      for (int j =0; j < n2+1; ++j) {
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
  string getSuperSeq(string& s1, string& s2, int n1, int n2) {
    string ans;

    while(n1 != 0 && n2 != 0) {
      if (s1[n1-1] == s2[n2-1]) {
        ans.push_back(s1[n1-1]);
        --n1;
        --n2;
      }
      else {
        if (dp[n1-1][n2] > dp[n1][n2-1]) {
          ans.push_back(s1[n1-1]);
          --n1;
        }
        else {
          ans.push_back(s2[n2-1]);
          --n2;
        }
      }
    }
    while (n1 > 0) {
      ans+=s1[n1-1];
      --n1;
    }
    while (n2 > 0) {
      ans+=s2[n2-1];
      --n2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
  /*
    void printLcs(string& s1, string& s2, int n1, int n2, vector<int>& index1, vector<int>& index2) {
      string res;
      while (n1 != 0 && n2 !=0) {
        if (s1[n1-1]== s2[n2-1]) {
          res.push_back(s1[n1-1]);
          index1.push_back(n1-1);
          index2.push_back(n2-1);
          --n1; --n2;
        }
        else {
          if (dp[n1-1][n2] > dp[n1][n2-1])
            --n1;
          else
            --n2;
        }
      }
      reverse(res.begin(), res.end());
    }
    string getSuperSeq(string& s1, string& s2, int n1, int n2, vector<int>& index1, vector<int>& index2, int len) {
      int i, j, k = j = i = 0;
      string ans;
      reverse(index1.begin(), index1.end());
      reverse(index2.begin(), index2.end());

   //   cout << "k " << k << " len " << len << endl;
      while(k < len) {
 //       cout << "i " << i << " k " << k << " index1[k] " << index1[k] << endl;
  //      cout << "j " << j << " k " << k << " index2[k] " << index2[k] << endl;
        while(i < n1 && i < index1[k])
          ans+=s1[i++];
        while(j < n2 && j < index2[k])
          ans+=s2[j++];
//        cout << "ans " << ans  << " s1[index[k]] " << s1[index1[k]]<< endl;

        ans+=s1[index1[k]];

        k++;
        i++;
        j++;
      }

      while(i < n1)
        ans+=s1[i++];
      while(j < n2)
        ans+=s2[j++];

      return ans;
    } 
    */
  string shortestCommonSupersequence(string str1, string str2) {
    vector<int>index1;
    vector<int>index2;
    int len = lcs(str1, str2, str1.length(), str2.length());
    //printLcs(str1, str2, str1.length(), str2.length(), index1, index2);
    return getSuperSeq(str1, str2, str1.length(), str2.length());
    //return getSuperSeq(str1, str2, str1.length(), str2.length(), index1, index2, len);
  }
};
