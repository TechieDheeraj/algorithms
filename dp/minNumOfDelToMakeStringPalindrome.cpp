/**
 *      file    :  minNumOfDelToMakeStringPalindrome.cpp
 *      author  :  techiedheeraj
 *      created :  2021 Jan 16 21:41:28
 *      lastMod :  Sat Jan 16 21:41:28 2021
 **/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int lps(string& s1, string& s2, int n) {
    for (int i =0; i < n+1; ++i) {
        for (int j = 0; j < n+1; ++j) {
            if (i ==0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (s1[i-1] == s2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int len = dp[n][n];
    return len;
 
    string ans;
    int n1 = n;
    int n2 = n;
    
    while (n1 != 0 && n2 !=0) {
        if (s1[n1-1] == s2[n2-1]) {
            ans.push_back(s1[n1-1]); --n1; --n2;
        }
        else {
            if (dp[n1-1][n2] > dp[n1][n2-1])
                --n1;
            else
                --n2;
        }
    }

    return ans.length() == len ? len: 0;
 }

int main() {
    int tt, n;
    string str;
    cin >> tt;
    while(tt--) {
        cin>>n;
        cin >> str;
        string rev = str;
        reverse(rev.begin(), rev.end());

        cout << n-lps(str, rev, n) << endl;
        
    }

	return 0;
}
