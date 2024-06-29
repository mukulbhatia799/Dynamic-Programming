/*
    // using recursion

    void findAns(int m, int n, int i, int j, int &count) {
        if(i == m && j == n) {
            count++;
            return ;
        }
        if(i+1 <= m) findAns(m, n, i+1, j, count);
        if(j+1 <= n) findAns(m, n, i, j+1, count);
    }
    int uniquePaths(int m, int n) {
        int i = 0, j = 0, count = 0;
        findAns(m-1, n-1, i, j, count);
        return count;
    }

    // T.C: O(2^m*n)
    // S.C: O(path length) =. O(m+n);

*/

/*
    // using memoization.

    int findAns(int m, int n, int i, int j, vector<vector<int>> &dp) {
        if(i == m && j == n) {
            return 1;
        }

        if(i > m || j > n) {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int down = findAns(m, n, i+1, j, dp);
        int right = findAns(m, n, i, j+1, dp);

        return dp[i][j] = down + right;
    }
    int uniquePaths(int m, int n) {
        // T.C => O(m*n)
        // S.C => O(m+n) + O(m*n) {stack space + aux array space}
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findAns(m-1, n-1, 0, 0, dp);
    }


 */

/*
    // using tabulation

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int down = 0, right = 0;
                if(i == 0 && j == 0) continue;
                if(i > 0) down = dp[i-1][j];
                if(j > 0) right = dp[i][j-1];
                dp[i][j] = down+right;
            }
        }
        return dp[m-1][n-1];
    }


*/

/*

    int uniquePaths(int m, int n) {
        // space optimization
        vector<int> dp1D(n, 0); // As only prev row is required to fill the curr row;
        int prev = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int down = 0, right = 0;
                if(i == 0 && j == 0) {
                    dp1D[j] = 1;
                    continue;
                }
                if(i > 0) down = dp1D[j];
                if(j > 0) right = prev;
                prev = right + down;
                dp1D[j] = prev;
            }
        }
        return prev;
    }


*/