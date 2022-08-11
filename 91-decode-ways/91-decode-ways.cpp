class Solution {
public:
    int numDecodings(string s)
{
    int n = s.length();

    if (s[0] == '0')
    {
        return 0;
    }

    vector<int> dp(n);
    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        if (s[i] != '0' && s[i - 1] != '0')
        {
            int f = s[i - 1] - '0';
            int sec = s[i] - '0';
            int val = f * 10 + sec;
            int ans = 0;
            if (val >= 10 && val <= 26)
            {
                ans = i - 2 >= 0 ? dp[i - 2] : 1;
            }
            dp[i] = dp[i - 1] + ans;
        }
        else if (s[i] == '0' && s[i - 1] != '0')
        {
            int f = s[i - 1] - '0';
            int sec = s[i] - '0';
            int val = f * 10 + sec;
            int ans = 0;
            if (val >= 10 && val <= 26)
            {
                ans = i - 2 >= 0 ? dp[i - 2] : 1;
            }
            dp[i] = ans;
        }
        else if (s[i] != '0' && s[i - 1] == '0')
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            dp[i] = 0;
        }
    }

    return dp[n - 1];
}
};