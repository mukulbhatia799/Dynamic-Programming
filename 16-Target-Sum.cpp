/*
    // using recursion
class Solution {
public:
    int findAns(int n, vector<int>& nums, int target, int pos, int neg) {
        if(n < 0) {
            return (pos+neg == target);
        }

        // positive value;
        int posSum = findAns(n-1, nums, target, pos+nums[n], neg);

        // negative value;
        int negSum = findAns(n-1, nums, target, pos, neg-nums[n]);

        return (posSum + negSum);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        return findAns(n-1, nums, target, 0, 0);
    }
};


*/

/*
    // using memoization
class Solution {
public:
    int findAns(int n, vector<int>& nums, int target, int pos, int neg, map<pair<int, int>, int> &dp) {
        if(n < 0) {
            return (pos+neg == target);
        }

        if(dp.find({pos, neg}) != dp.end()) return dp[{pos, neg}];

        // positive value;
        int posSum = findAns(n-1, nums, target, pos+nums[n], neg, dp);

        // negative value;
        int negSum = findAns(n-1, nums, target, pos, neg-nums[n], dp);

        return dp[{pos, neg}] = (posSum + negSum);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // using memoization
        int n = nums.size();

        map<pair<int, int>, int> dp;

        return findAns(n-1, nums, target, 0, 0, dp);
    }
};


*/


/*

// (another data structure for memoization approach): using vector of vectors and taking 2*sum of size where 1 to sum is for -ve values and sum+1 to 2*sum is for positive values.
// as using map, we are taking log(n) in every iteration to insert value in it. So, we can reduce it using vector of vectors which takes O(1) time to insert.


class Solution {
public:
    int findAns(int n, vector<int>& nums, int target, int pos, int neg, int sum, vector<vector<int>> &dp) {
        if(n < 0) {
            return (pos+neg == target);
        }

        int col = (pos+neg <= 0) ? abs(pos+neg) : sum+abs(pos+neg);
        if(dp[n][col] != -1) return dp[n][col];

        // positive value;
        int posSum = findAns(n-1, nums, target, pos+nums[n], neg, sum, dp);

        // negative value;
        int negSum = findAns(n-1, nums, target, pos, neg-nums[n], sum, dp);

        return dp[n][col] = (posSum + negSum);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // using memoization
        int n = nums.size();

        int sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];

        vector<vector<int>> dp(n, vector<int> ((sum+1)*2, -1));

        return findAns(n-1, nums, target, 0, 0, sum, dp);
    }
};

*/

/*



*/

/*



*/