/*

//  ================ using recursion ================ 

#include <bits/stdc++.h> 
int findAnsRE(int ind, vector<int> &nums) {
    if(ind == 0) return nums[0];
    if(ind < 0) return 0;

    int pick = nums[ind] + findAnsRE(ind-2, nums);
    int notPick = 0 + findAnsRE(ind-1, nums);

    return max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    return findAnsRE(nums.size()-1, nums);   // using recursion
}


// T.C: O(2^N)
// S.C: O(N) {aux stack space}

*/

/*

//  ================= using memoization ================= 

#include <bits/stdc++.h> 
int findAnsRE(int ind, vector<int> &nums, vector<int> &dp) {
    if(ind == 0) return nums[0];
    if(ind < 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int pick = nums[ind] + findAnsRE(ind-2, nums, dp);
    int notPick = 0 + findAnsRE(ind-1, nums, dp);

    return dp[ind] = max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size(), -1);
    return findAnsRE(nums.size()-1, nums, dp);   // using memoization
}

// T.C: O(N)
// S.C: O(N) + O(N) {aux stack space + aux array space}

*/

/*

//  ================= using tabulation ================= 

#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    // done using tabulation.
    vector<int> dp(nums.size(), -1);
    dp[0] = nums[0];

    int whenAt0 = nums[0], lessThan0 = 0;       // not used here, but just want to tell that when changing from memo -> tabulation, we just go from bottom to top means from the base cases to the nth value.
    
    for(int i = 1; i < nums.size(); i++) {
        int pick = nums[i];
        if(i > 1) pick += dp[i-2];
        int notPick = 0 + dp[i-1];
        dp[i] = max(pick, notPick);
    }
    return dp[nums.size()-1];
}

// T.C: O(N)
// S.C: O(N) {aux array space}

*/

/*

//  ================= using space optimization ================= 

#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    // using space optimization;
    int prev1 = nums[0], prev2 = 0;
    for(int i = 1; i < nums.size(); i++) {
        int take = nums[i];
        if(i > 1) take += prev2;
        int notTake = 0 + prev1;
        prev2 = prev1;
        prev1 = max(take, notTake);
    }
    return prev1;
}

// T.C: O(N)
// S.C: O(1)

*/