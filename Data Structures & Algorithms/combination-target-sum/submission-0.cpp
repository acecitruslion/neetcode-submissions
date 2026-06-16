class Solution {
public:

    void f(int i, vector<int>& nums, vector<vector<int>>& res, vector<int>& v, int sum, int target) {
        if(sum == target) {
            res.push_back(v);
            return;
        }
        
        if(sum > target || i >= nums.size()) {
            return;
        }

        v.push_back(nums[i]);
        f(i, nums, res, v, sum+nums[i], target);
        v.pop_back();
        f(i+1, nums, res, v, sum, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> v;
        f(0, nums, res, v, 0, target);
        return res;
    }
};
