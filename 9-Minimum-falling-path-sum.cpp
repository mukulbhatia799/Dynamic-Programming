/*

class Solution {
public:
    int findAns(int n, int i, int j, vector<vector<int>> &matrix) {
        if(i > n || j > n) return 0;
        if(i == n) return matrix[i][j];

        int btm = INT_MAX, btm_right = INT_MAX, btm_left = INT_MAX;
        if(j != 0) btm_left = matrix[i][j] + findAns(n, i+1, j-1, matrix);
        btm = matrix[i][j] + findAns(n, i+1, j, matrix);
        if(j != n) btm_right = matrix[i][j] + findAns(n, i+1, j+1, matrix);
        return min(btm, min(btm_left, btm_right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        // using recursion
        int n = matrix.size();
        int mini = INT_MAX;
        for(int j = 0; j < n; j++) {
            int sum = findAns(n-1, 0, j, matrix);
            mini = min(mini, sum);
        }
        return mini;
    }
};

*/


/*

class Solution {
public:
    int findAns(int n, int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        if(i > n || j > n) return 0;
        if(i == n) return matrix[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int btm = INT_MAX, btm_right = INT_MAX, btm_left = INT_MAX;

        if(j != 0) btm_left = matrix[i][j] + findAns(n, i+1, j-1, matrix, dp);
        btm = matrix[i][j] + findAns(n, i+1, j, matrix,dp);
        if(j != n) btm_right = matrix[i][j] + findAns(n, i+1, j+1, matrix, dp);
        
        return dp[i][j] = min(btm, min(btm_left, btm_right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        // using memoization
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int mini = INT_MAX;
        for(int j = 0; j < n; j++) {
            int sum = findAns(n-1, 0, j, matrix, dp);
            mini = min(mini, sum);
        }
        return mini;
    }
};

*/


/*

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // using tabulation
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0) {
                    dp[i][j] = matrix[i][j];
                }
                else {
                    int up = INT_MAX, up_left = INT_MAX, up_right = INT_MAX;
                    if(j != 0) up_left = dp[i-1][j-1];
                    up = dp[i-1][j];
                    if(j != n-1) up_right = dp[i-1][j+1];
                    dp[i][j] = min(up, min(up_left, up_right)) + matrix[i][j];
                }
            }
        }

        int mini = INT_MAX;
        for(int i = 0; i < n; i++) {
            mini = min(dp[n-1][i], mini);
        }

        return mini;
    }
};

*/


/*

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // space optimization
        int n = matrix.size();
        vector<int> prev(n, 0);
        int prev_left = INT_MAX;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0) {
                    prev[j] = matrix[0][j];
                }
                else {
                    int up = INT_MAX, up_left = INT_MAX, up_right = INT_MAX;
                    
                    if(j != 0) up_left = prev_left;
                    up = prev[j];
                    if(j != n-1) up_right = prev[j+1];
                    
                    prev_left = prev[j];
                    prev[j] = min(up, min(up_left, up_right)) + matrix[i][j];
                }
            }
        }
        int mini = INT_MAX;
        for(int i = 0; i < n; i++) {
            mini = min(mini, prev[i]);
        }

        return mini;
    }
};

*/