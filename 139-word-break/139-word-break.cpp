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

    vector<int> dp(n + 1, -1); // output->[i] -> n size ke liye ans;

    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        string s1;
        for (int j = i; j < n; j++)
        {
            s1 += s[j];
            if (mymap.count(s1) == 1 && dp[j + 1] == 1)
            {
                dp[i] = 1;
            }
        }
        if (dp[i] == -1)
        {
            dp[i] = 0;
        }
    }
    return dp[0];
}
};