/**
 *      file    :  shortestCommonSuperSequence.cpp
 *      author  :  techiedheeraj
 *      created :  2021 Jan 16 15:22:54
 *      lastMod :  Sat Jan 16 15:22:54 2021
 **/

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(char* , char*, int, int );

int main()
{   
    
    int t;
    char X[10001], Y[10001];
    
    //taking total testcases
    cin >> t;
    while(t--){
    
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	cout << shortestCommonSupersequence(X, Y, strlen(X), strlen(Y))<< endl;
    }
	return 0;
}

// } Driver Code Ends


//User function template for C++

// X : 1st given string of size m
// Y : 2nd given string of size n
//int dp[10001][10001];
int lcs(char *s1, char* s2, int n1, int n2) {
    int dp[n1+1][n2+1];
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
    int len = dp[n1][n2];
    string res;
    
    while(n1 != 0 && n2!=0) {
        if (s1[n1-1] == s2[n2-1]) {
            res.push_back(s1[n1-1]);
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
    return (res.length() == len) ? len : 0;
}
int shortestCommonSupersequence(char* X, char* Y, int m, int n) {
    //code here
    int ret = lcs(X, Y, m, n);
    return m+n - ret; 
}
