class Solution {
public:

    vector<vector<int>> dp;
    int totalSum;

    int f(int i, int total, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(i == nums.size()) {
            return total == target;
        }

        if(dp[i][total+totalSum] != INT_MIN) return dp[i][total+totalSum];

        dp[i][total + totalSum] = f(i+1, total+nums[i], target, nums, dp) + f(i+1, total-nums[i], target, nums, dp);

        return dp[i][total+totalSum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        dp = vector<vector<int>>(nums.size(), vector<int>(2 * totalSum + 1, INT_MIN));

        return f(0, 0, target, nums, dp);
    }
};