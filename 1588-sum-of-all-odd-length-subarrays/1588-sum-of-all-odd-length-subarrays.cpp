class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& ar) {
        int n = ar.size();
        int ans = 0;
        vector<vector<int>> dp(n , vector<int>(n));
        int j = 0;
        for(int i =0  ; j < n && i < n ; i++ , j++){
            dp[i][j] = ar[i];
            ans += dp[i][j];
        }
        
        
        for(int k = 1; k < n ; k++){
            int j = k;
            bool flag = false;
            if(k % 2 == 0)
            {
                flag = true;
            }
            for(int i = 0 ;j < n && i < n ; i++ , j++){
                dp[i][j] = ar[j] + dp[i][j - 1];
                if(flag){
                    ans += dp[i][j];
                }
            }
        }
        return ans;
        
        
    }
};