class Solution {
public:
   int lengthOfLIS(vector<int> &ar)
{
    int n = ar.size();
    if(n <= 1){
        return n;
    }
    vector<int> dp(n);
    dp[0] = 1;
    int maxi = 1;
    for (int i = 1; i < n; i++)
    {
        int ans = 0;
        for (int j = 0; j < i; j++)
        {
            if (ar[j] < ar[i])
            {
                ans = max(ans, dp[j]);
            }
        }
        dp[i] = ans + 1;
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}
};