class Solution {
public:
bool wordBreak(string s, vector<string> &v)
{
    unordered_map<string, int> mymap;

    for (int i = 0; i < v.size(); i++)
    {
        mymap[v[i]]++;
    }

    int n = s.length();

    vector<int> dp(n + 1, -1);

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        string s1 = "";
        for (int j = n - i; j < n; j++)
        {
            s1 += s[j];
            if (mymap.count(s1) == 1 && dp[n - j - 1] == 1)
            {
                dp[i] = 1;
            }
        }
        if (dp[i] == -1)
        {
            dp[i] = 0;
        }
    }

    return dp[n];
}
};