/*

class Solution {
public:
    int findAns(int row, int i, int j, vector<vector<int>>& triangle) {
        if(i > row || j > row) return 0;
        int btm = triangle[i][j] + findAns(row, i+1, j, triangle);
        int btm_right = triangle[i][j] +  findAns(row, i+1, j+1, triangle);
        return min(btm, btm_right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // using recursion
        int row = triangle.size()-1;
        return findAns(row, 0, 0, triangle);
    }
};

*/


/*

class Solution {
public:
    int findAns(int row, int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(i > row || j > i) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int btm = triangle[i][j] + findAns(row, i+1, j, triangle, dp);
        int btm_right = triangle[i][j] + findAns(row, i+1, j+1, triangle, dp);
        return dp[i][j] = min(btm, btm_right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // using memoization
        int row = triangle.size();
        vector<vector<int>> dp;
        for(int i = 1; i <= row; i++) {
            dp.push_back(vector<int>(i, -1));
        }

        return findAns(row-1, 0, 0, triangle, dp);
    }
};

*/


/*

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        // using tabulation
        vector<vector<int>> dp;
        for(int i = 1; i <= row; i++) {
            dp.push_back(vector<int>(i, -1));
        }

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < i+1; j++) {
                if(i == 0) dp[i][j] = triangle[i][j];
                else {
                    int up = INT_MAX, up_left = INT_MAX;
                    if(j != i) {
                        up = dp[i-1][j];
                    }
                    if(j != 0) {
                        up_left = dp[i-1][j-1];
                    }
                    dp[i][j] = min(up, up_left) + triangle[i][j];
                }
            }
        }
        int min_answer = INT_MAX;
        for(int i = 0; i < row; i++) {
            min_answer = min(min_answer, dp[row-1][i]);
        }
        return min_answer;
    }
};

*/


/*

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // using space optimization
        // as we just need previous row to fill curr row; 
        int row = triangle.size();
        vector<int> dp(row);
        int prev;   // as top-prev will get updated so we need to store it somewhere.
        for(int i = 0; i < row; i++) {
            for(int j = 0; j <= i; j++) {
                if(i == 0) {
                    dp[0] = triangle[0][0];
                }
                else {
                    int up = INT_MAX, up_left = INT_MAX;
                    if(j != 0) {
                        up_left = prev;
                    }
                    if(j != i) {
                        up = dp[j];
                    }
                    prev = dp[j];
                    dp[j] = min(up_left, up) + triangle[i][j];
                }
            }
        }
        int mini = INT_MAX;
        for(int i = 0; i < dp.size(); i++) {
            mini = min(mini, dp[i]);
        }
        return mini;
    }
};

*/