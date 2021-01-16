/**
 *      file    :  minNumOfInsDel.cpp
 *      author  :  techiedheeraj
 *      created :  2021 Jan 16 18:02:30
 *      lastMod :  Sat Jan 16 18:02:30 2021
 **/

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
		int dp[1001][1001];

		int lcs(string& s1, string& s2, int n1, int n2) {
			for (int i =0; i < n1+1; i++) {
				for (int j =0; j < n2+1; j++) {
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
			return res.length() == len ? len : 0;
		}
		int minOperations(string str1, string str2) 
		{ 
			int len = lcs(str1, str2, str1.length(), str2.length()); 
			int minDel = str1.length()-len;
			int minIns = str2.length()-len;

			return minDel + minIns;
		} 
};

int main() 
{
	int t;
	cin >> t;
	while (t--)
	{
		string s1, s2;
		cin >> s1 >> s2;

		Solution ob;
		cout << ob.minOperations(s1, s2) << "\n";

	}
	return 0;
}
