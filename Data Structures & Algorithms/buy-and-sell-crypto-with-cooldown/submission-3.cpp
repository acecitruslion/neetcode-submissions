class Solution {
public:

    int f(int ind, bool can_buy, vector<int>& prices, vector<vector<int>>& dp) {
        if(ind >= prices.size()) return 0;

        if(dp[ind][can_buy] != -1) return dp[ind][can_buy];
        
        if(can_buy) {
            int buy = -prices[ind] + f(ind+1, 0, prices, dp);
            int skip = f(ind+1, 1, prices, dp);

            return dp[ind][can_buy] = max(buy, skip);
        }

        else {
            int sell = prices[ind] + f(ind+2, 1, prices, dp);
            int hold = f(ind+1, 0, prices, dp);

            return dp[ind][can_buy] = max(sell, hold);
        }
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+2, vector<int>(2, -1));
        // return f(0, 1, prices, dp);

        int n = prices.size();

        dp[n][0] = dp[n][1] = 0;
        dp[n + 1][0] = dp[n + 1][1] = 0;

        for(int i=prices.size()-1;i>=0;i--) {
            dp[i][1] = max(-prices[i]+dp[i+1][0], dp[i+1][1]);
            dp[i][0] = max(prices[i]+dp[i+2][1], dp[i+1][0]);
        }
        return dp[0][1];
    }
};
