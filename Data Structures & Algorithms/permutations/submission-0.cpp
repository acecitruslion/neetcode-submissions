class Solution {
public:

    vector<vector<int>> res;

    void f(vector<int>& nums, int i, vector<int>& c, vector<int>& vis) {
        if(c.size() == nums.size()) {
            res.push_back(c);
            return;
        }
        if(i == nums.size()) {
            return;
        }

        for(int idx=0;idx<nums.size();idx++) {
            if(vis[idx] == 0) {
                c.push_back(nums[idx]);
                vis[idx] = 1;
                f(nums, idx, c, vis);
                vis[idx] = 0;
                c.pop_back();
            }
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        vector<int> c;
        vector<int> vis(nums.size(), 0);
        f(nums, 0, c, vis);
        return res;
    }
};
