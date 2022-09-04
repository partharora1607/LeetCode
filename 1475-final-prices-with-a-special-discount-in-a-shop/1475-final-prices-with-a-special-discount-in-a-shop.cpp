class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n);
        dp[n - 1] = prices[n - 1];
        for(int i = n - 2 ; i >= 0 ; i--){
            int j = i + 1;
            for(; j < n ; j ++){
                if(prices[j] <= prices[i]){
                    break;
                }
            }
            if(j != n){
                dp[i] = prices[i]-prices[j];
            }
            else{
                dp[i] = prices[i];
            }
        }
        return dp;
    }
};