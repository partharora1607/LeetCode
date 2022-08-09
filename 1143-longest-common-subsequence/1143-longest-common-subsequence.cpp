class Solution {
public:
int longestCommonSubsequence(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> output(m + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++)
    {
        output[i][0] = 0;
    }

    for (int j = 0; j < n; j++)
    {
        output[0][j] = 0;
    }

    // i -> m -> s1
    // j - >n -> s2

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[m -i] == s2[n - j]){
                output[i][j] = 1 + output[i - 1][j - 1];
            }
            else{
                int op1 = output[i][j - 1];
                int op2 = output[i - 1][j];
                output[i][j] = max(op1 , op2);
            }
        }
    }

    return output[m][n];

}

};