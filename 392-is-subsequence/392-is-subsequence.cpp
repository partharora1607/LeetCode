class Solution {
public:
bool isSubsequence(string s, string t)
{
    int m = s.length();
    int n = t.length();
    vector<vector<int>> output(m + 1, vector<int>(n + 1, -1));

    // m -> s ->i
    // n - > r -> j

    for (int j = 0; j <= n; j++)
    {
        output[0][j] = 1;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i > j)
            {
                output[i][j] = 0;
            }
            else if (s[m - i] == t[n - j])
            {
                output[i][j] = output[i - 1][j - 1];
            }
            else
            {
                output[i][j] = output[i][j - 1];
            }
        }
    }
    return output[m][n];
}
};