class Solution {
public:
    int helper(vector<int> &ar, int si, int ei, int prev_i, vector<int> &dp)
{
    if (si > ei)
    {
        return 0;
    }

    if (dp[prev_i + 1] != -1)
    {
        return dp[prev_i + 1];
    }

    int op1 = helper(ar, si + 1, ei, prev_i, dp);

    int op2 = INT_MIN;
    if (prev_i == -1 || ar[si] > ar[prev_i])
    {
        op2 = helper(ar, si + 1, ei, si, dp) + 1;
    }

    dp[prev_i + 1] = max(op1 , op2);
    return dp[prev_i + 1];

}

int lengthOfLIS(vector<int> &ar)
{
    int n = ar.size();
    vector<int> dp(n + 1, -1);
  return  helper(ar, 0, n - 1, -1, dp);
}
};