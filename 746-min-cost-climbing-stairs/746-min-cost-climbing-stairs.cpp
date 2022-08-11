class Solution {
public:
int minCostClimbingStairs(vector<int> &ar)
{
    int n = ar.size();
    vector<int> dp(n);
    dp[n - 1] = ar[n - 1];
    dp[n - 2] = ar[n - 2];
    for (int i = n - 3; i >= 0; i--)
    {
        dp[i] = min(dp[i + 1], dp[i + 2]) + ar[i];
    }
    return min(dp[0], dp[1]);
}
};