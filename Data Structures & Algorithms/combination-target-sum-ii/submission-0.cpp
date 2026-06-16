class Solution {
public:

    void f(vector<int>& candidates, vector<int>& curr, vector<vector<int>>& res, int target, int sum, int i) {
        if(sum == target) {
            res.push_back(curr);
            return;
        }
        if(sum > target) return;
        if(i == candidates.size()) return;

        curr.push_back(candidates[i]);
        f(candidates, curr, res, target, sum + candidates[i], i+1);

        while(i+1 < candidates.size() && candidates[i] == candidates[i+1]) {
            i++;
        }
        curr.pop_back();
        f(candidates, curr, res, target, sum, i+1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;

        sort(candidates.begin(), candidates.end());
        f(candidates, curr, res, target, 0, 0);
        return res;
    }
};
