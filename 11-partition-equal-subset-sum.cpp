/*
    // using recursion
class Solution {
public:
    bool findAns(int n, int target, vector<int>& nums) {
        if(n == 0) return (target == nums[0]);
        
        bool take = false;
        if(nums[n] <= target) take = findAns(n-1, target-nums[n], nums);
        
        bool notTake = findAns(n-1, target, nums);

        return take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        // using recursion
        int n = nums.size();
        int target = 0;
        for(int i = 0; i < nums.size();i++) {
            target += nums[i];
        }
        if(target & 1) return false;        // if sum is odd then we can't divide it in two subsets.

        return findAns(n-1, target/2, nums);
    }
};


*/

/*
    // using memoization
class Solution {
public:
    bool findAns(int n, int target, vector<int>& nums, vector<vector<int>> &dp) {
        if(n == 0) return (target == nums[0]);
        
        if(dp[n][target] != -1) return dp[n][target];

        bool take = false;
        if(nums[n] <= target) take = findAns(n-1, target-nums[n], nums, dp);
        
        bool notTake = findAns(n-1, target, nums, dp);

        return dp[n][target] = take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        // using memoization
        int n = nums.size();
        int target = 0;
        for(int i = 0; i < nums.size();i++) {
            target += nums[i];
        }
        if(target & 1) return false;        // if sum is odd then we can't divide it in two subsets.
        target /= 2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        return findAns(n-1, target, nums, dp);
    }
};


*/

/*



*/

/*



*/