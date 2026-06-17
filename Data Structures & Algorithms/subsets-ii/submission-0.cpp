class Solution {
public:

    vector<vector<int>> res;

    void f(vector<int>& nums, int i, vector<int>& curr) {
        if(i == nums.size()) {
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        f(nums, i+1, curr);
        while(i+1 < nums.size() && nums[i] == nums[i+1]) {
            i++;
        }
        curr.pop_back();
        f(nums, i+1, curr);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        res.clear();
        sort(nums.begin(), nums.end());
        f(nums, 0, curr);
        return res;
    }
};