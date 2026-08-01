class Solution {
public:

    int f(int ind, int amt, vector<int>& coins, vector<vector<int>>& dp) {
        if(amt == 0) {
            return 1;
        }
        if(amt < 0) {
            return 0;
        }
        if(ind == coins.size()) {
            return 0;
        }
        if(dp[ind][amt] != -1e9) return dp[ind][amt];

        int stay = f(ind, amt-coins[ind], coins, dp);
        int go = f(ind+1, amt, coins, dp);

        return dp[ind][amt] = go + stay;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1e9));
        return f(0, amount, coins, dp);
    }
};
