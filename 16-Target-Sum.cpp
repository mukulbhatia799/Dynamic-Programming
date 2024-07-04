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



*/

/*



*/