/*
    // using recursion

    int findAns(int m, int n, vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[m][n] == 1) return 0;   // should be in starting as the starting point can also have 1(obstacle).
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;

        int left = 0, up = 0;
        if(m > 0) up = findAns(m-1, n, obstacleGrid);
        if(n > 0) left = findAns(m, n-1, obstacleGrid);
        return up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // using recursion
        int m = obstacleGrid.size()-1;
        int n = obstacleGrid[0].size()-1;

        return findAns(m, n, obstacleGrid);
    }

*/


/*

class Solution {
public:
    int findAns(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int> > &dp) {
        if(obstacleGrid[m][n] == 1) return 0;   // should be in starting as the starting point can also have 1(obstacle).
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;

        if(dp[m][n] != 0) return dp[m][n];

        int left = 0, up = 0;
        if(m > 0) up = findAns(m-1, n, obstacleGrid, dp);
        if(n > 0) left = findAns(m, n-1, obstacleGrid, dp);
        return dp[m][n] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // using memoization
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int> > dp(m, vector<int>(n, 0));

        return findAns(m-1, n-1, obstacleGrid, dp);
    }
};

*/

/*

class Solution {
public:
    int findAns(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int> > &dp) {
        if(obstacleGrid[m][n] == 1) return 0;   // should be in starting as the starting point can also have 1(obstacle).
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;

        if(dp[m][n] != 0) return dp[m][n];

        int left = 0, up = 0;
        if(m > 0) up = findAns(m-1, n, obstacleGrid, dp);
        if(n > 0) left = findAns(m, n-1, obstacleGrid, dp);
        return dp[m][n] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // using tabulation
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int> > dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if(i == 0 && j == 0) dp[0][0] = 1;
                else {
                    int up = 0, left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = up+left;
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};

 */



/*

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // using space optimization
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> dp(n, 0);
        int prev = 0;
        for(int i = 0; i < m; i++) {
            prev = 0;
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    prev = dp[j] = 0;
                }
                else if(i == 0 && j == 0) {
                    prev = dp[j] = 1;
                }
                else {
                    int up = 0;
                    if(i > 0) up = dp[j];
                    dp[j] = up+prev;
                    prev = dp[j];
                }
            }
            cout << endl;
        }
        
        return dp[n-1];
    }
};

*/