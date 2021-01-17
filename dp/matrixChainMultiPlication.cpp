/**
 *      file    :  matrixChainMultiPlication.cpp
 *      author  :  techiedheeraj
 *      created :  2021 Jan 17 16:27:19
 *      lastMod :  Sun Jan 17 16:27:19 2021
 **/

#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

class Solution {
	public:
		int size;
		int dp[101][101];

		Solution(int s): size(s) {}

		// Recursive solution 
		int matrixChainMul1(vector<int>& arr, int i, int j) {
			if (i >= j) return 0;

			int res = INT_MAX;
			
			for (int k = i; k < j; ++k) {
				int ans = matrixChainMul1(arr, i, k) + matrixChainMul1(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]); 
				res = min(res, ans);
			}
			return res;
		}

		int matrixChainMul2(vector<int>& arr, int i, int j) {
			if (i >= j) return 0;

			if (dp[i][j] != -1) return dp[i][j];
			int res = INT_MAX;

			for (int k = i; k < j; ++k) {
				res = min(matrixChainMul2(arr, i, k)+matrixChainMul2(arr, k+1, j) + (arr[i-1]*arr[k]*arr[j]), res);
			}
			return dp[i][j] = res;
		}

		int matrixChainMulitplication(vector<int>&arr, int i, int j) {
			auto start = high_resolution_clock::now();
			int result =  matrixChainMul1(arr, i, j);
//			int result =  matrixChainMul2(arr, i, j);
			auto end = high_resolution_clock::now();
			cout << "Algorithm Time:  " << duration_cast<microseconds>(end-start).count() << endl; 
			return result;
		}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	int size;

	cout << "Enter Size of Array" << endl;
	cin >> size; 

	Solution *obj = new Solution(size);
	memset(obj->dp, -1, sizeof(obj->dp));

	vector<int> arr(size);

	cout << "Enter elements" << endl;
	for (int i =0; i < size; ++i)
		cin >> arr[i]; 

	int res = obj->matrixChainMulitplication(arr, 1, size-1);
	cout << "Minimum number of operation " << res << endl;

  return 0;
}    
