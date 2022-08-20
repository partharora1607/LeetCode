class Solution {
public:
int countSubstrings(string s)
{
    int m = s.length();
    vector<vector<int>> dp(m, vector<int>(m ,1));

    int count = m;

    for (int i = 0; i < m; i++)
    {   
       dp[i][i] = 1;
    }
    for (int d = 1; d < m; d++)
    {   
        int i = 0;
        for (int j = d; j < m; j++ ,i++)
        {   
            if(s[i] != s[j]){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = dp[i + 1][j-1];
            }
            count+= dp[i][j];
        }
    }
    return count;

}
};