/*

class Solution {
public:
    int findAns(int m, int n, vector<vector<int>>& grid) {
        if(m == 0 && n == 0) return grid[0][0];
        if(m < 0 || n < 0) return INT_MAX;

        int up = INT_MAX;
        if(m > 0) up = grid[m][n] + findAns(m-1, n, grid);
        int left = INT_MAX;
        if(n > 0) left = grid[m][n] + findAns(m, n-1, grid);
        return min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        // using recursion
        int m = grid.size();
        int n = grid[0].size();

        return findAns(m-1, n-1, grid);
    }
};

*/

/*

class Solution {
public:
    int findAns(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(m == 0 && n == 0) return grid[0][0];
        if(m < 0 || n < 0) return INT_MAX;

        if(dp[m][n] != -1) return dp[m][n];

        int up = INT_MAX;
        if(m > 0) up = grid[m][n] + findAns(m-1, n, grid, dp);
        int left = INT_MAX;
        if(n > 0) left = grid[m][n] + findAns(m, n-1, grid, dp);
        return dp[m][n] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        // using memoization
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return findAns(m-1, n-1, grid, dp);
    }
};

*/

/*
    // using tabulation

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) dp[i][j] = grid[0][0];
                else {
                    int up = INT_MAX, left = INT_MAX;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = min(up, left) + grid[i][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};

*/


/*
    // using space optimization

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp1D(n, -1);
        int prev = -1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) prev = dp1D[0] = grid[0][0];
                else {
                    int up = INT_MAX, left = INT_MAX;
                    if(i > 0) up = dp1D[j];
                    if(j > 0) left = prev;
                    dp1D[j] = min(up,left) + grid[i][j];
                    prev = dp1D[j];
                }
            }
        }

        return prev;
    }
};

*/