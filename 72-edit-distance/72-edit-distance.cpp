class Solution {
public:
    int minDistance(string s, string t)
{
    int m = s.length();
    int n = t.length();
    int **ar = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        ar[i] = new int[n + 1];
    }
    for (int i = 0; i <= m; i++)
    {
        ar[i][0] = i;
    }
    for (int j = 0; j <= n; j++)
    {
        ar[0][j] = j;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m - i] == t[n - j])
            {
                ar[i][j] = ar[i - 1][j - 1];
            }
            else
            {
                int op1 = ar[i - 1][j] + 1;
                int op2 = ar[i - 1][j - 1] + 1;
                int op3 = ar[i][j - 1] + 1;
                ar[i][j] = min(op1, min(op2, op3));
            }
        }
    }
    return ar[m][n];
}
};