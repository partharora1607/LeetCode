class Solution {
public:
   int minCut(string s)
{
    int n = s.length();
    vector<vector<int>> dp1(n, vector<int>(n, 0));

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        dp1[i][j] = 1;
        j++;
    }

    j = 1;
    for (int i = 0; j < n && i < n; i++, j++)
    {
        if (s[i] == s[j])
        {
            dp1[i][j] = 1;
        }
        else
        {
            dp1[i][j] = 0;
        }
    }

    for (int k = 1; k < n; k++)
    {
        int j = k + 1;
        for (int i = 0; j < n && i < n; i++, j++)
        {
            if (s[i] != s[j])
            {
                dp1[i][j] = 0;
            }
            else
            {
                dp1[i][j] = dp1[i + 1][j - 1];
            }
        }
    }

    vector<int> dp2(n);
    dp2[0] = 0;
    for (int j = 1; j < n; j++)
    {
        if(dp1[0][j] == 1){
            dp2[j] = 0;
        }
        else{
                    int ans = INT_MAX;
        for (int i = j; i >= 1; i--)
        {
            if(dp1[i][j])
            {
                ans = min(ans ,1 + dp2[i - 1]);
            }
        }
        dp2[j] = ans;
            
        }

    }
    return dp2[n - 1];
}

};