/**
 *      file    :  64_minPathSum.cpp
 *      author  :  techiedheeraj
 *      created :  2020 Dec 11 03:03:07
 *      lastMod :  Fri Dec 11 03:03:07 2020
 **/

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		
		for(int i =1; i < m; ++i)
			grid[i][0] += grid[i-1][0];
		
		for(int i =1 ; i < n; ++i)
			grid[0][i] += grid[0][i-1];
		
		for (int i = 1; i < m; ++i) {
		 for (int j = 1; j < n; ++j) {
			 grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
		 }
		}

		return grid[m-1][n-1];
	}
};
