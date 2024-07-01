/*
    // using backtracking
class Solution {
public:
    void findSubsets(int size, vector<int> &nums, vector<vector<int>> &store, vector<int> sub) {
        if(size < 0) {
            store.push_back(sub);
            return ;
        }

        // take it
        sub.push_back(nums[size]);
        findSubsets(size-1, nums, store, sub);

        // don't take it
        sub.pop_back();
        findSubsets(size-1, nums, store, sub);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> store;
        vector<int> sub;
        findSubsets(nums.size()-1, nums, store, sub);
        return store;
    }
};

*/