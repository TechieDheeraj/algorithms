/**
 *      file    :  longestRepeatingSubsequence.cpp
 *      author  :  techiedheeraj
 *      created :  2021 Jan 17 01:47:46
 *      lastMod :  Sun Jan 17 01:47:46 2021
 **/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int dp[501][501];
		int lcs(string& s1, string& s2, int n1, int n2) {
			for (int i = 0; i < n1+1; ++i) {
				for (int j = 0; j < n2+1; ++j) {
					if (i == 0 || j == 0) {
						dp[i][j] = 0;
						continue;
					}
					if (s1[i-1] == s2[j-1] && i != j)
						dp[i][j] = 1+dp[i-1][j-1];
					else
						dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
			int len = dp[n1][n2];
			return len;
		}
		int LongestRepeatingSubsequence(string str){
			return lcs(str, str, str.length(), str.length());
		}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
