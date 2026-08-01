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
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));
        for(int i=0;i<amount+1;i++) {
            if(i%coins[0] == 0) dp[0][i] = 1;
        }
        for(int i=1;i<coins.size();i++) {
            for(int j=0;j<amount+1;j++) {
                if(j >= coins[i]) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[coins.size()-1][amount];
    }
};
