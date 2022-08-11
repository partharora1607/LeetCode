class Solution {
public:
   int longestIdealString(string s, int k)
{
    int n = s.size();
    vector<int> dp(26, 0);
    dp[s[n - 1] - 'a'] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        int lb = max(0, (s[i] - 'a') - k);
        int hb = min(25, (s[i] - 'a') + k);

        int ans = 0;

        for (int i = lb; i <= hb; i++)
        {
            ans = max(ans, dp[i]);
        }
        dp[s[i] - 'a'] = max(dp[s[i] - 'a'], ans + 1);
    }
    return *max_element(dp.begin() , dp.end());
}
};