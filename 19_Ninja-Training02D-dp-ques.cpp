// using recursion

// int findAns(int n, vector<vector<int>>& points, int prevTaken) {
//     if(n == 0) {
//         int maxi = 0;
//         for(int i = 0; i < 3; i++) {
//             if(i != prevTaken) maxi = max(maxi, points[0][i]);
//         }
//         return maxi;
//     }

//     int maxi = 0;
//     for(int i = 0; i < 3; i++) {
//         if(i != prevTaken) {
//             maxi = max(maxi, points[n][i] + findAns(n-1, points, i));
//         }
//     }

//     return maxi;
// }

// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     // using recursion
    
//     return findAns(n-1, points, 3);
// }



// using memoization

// int findAns(int n, vector<vector<int>>& points, int prevTaken, vector<vector<int>>& dp) {
//     if(n == 0) {
//         int maxi = 0;
//         for(int i = 0; i < 3; i++) {
//             if(i != prevTaken) maxi = max(maxi, points[0][i]);
//         }
//         return maxi;
//     }

//     if(dp[n][prevTaken] != -1) return dp[n][prevTaken];
//     int maxi = 0;
//     for(int i = 0; i < 3; i++) {
//         if(i != prevTaken) {
//             maxi = max(maxi, points[n][i] + findAns(n-1, points, i, dp));
//         }
//     }

//     return dp[n][prevTaken] = maxi;
// }

// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     // using memoization
    
//     vector<vector<int>> dp(n, vector<int>(4, -1));
//     return findAns(n-1, points, 3, dp);
// }