class Solution {
public:
bool isMatch(string s, string p, int **ar, int m, int n)
{
    if (n == 0)
    {
        return m == 0;
    }

    if (ar[m][n] != -1)
    {
        return ar[m][n];
    }

    if (n > 1 && p[1] == '*')
    {
        if (isMatch(s, p.substr(2), ar, m, n - 2))
        {
            return true;
        }
        if (s[0] == p[0] || p[0] == '.' && m > 0)
        {
            ar[m][n] = isMatch(s.substr(1), p, ar, m - 1, n);
            return ar[m][n];
        }
        return false;
    }
    if (s[0] == p[0] || p[0] == '.' && m > 0)
    {
        ar[m][n] = isMatch(s.substr(1), p.substr(1), ar, m - 1, n - 1);
        return ar[m][n];
    }
    return false;
}

bool isMatch(string s, string p)
{
    int m = s.length();
    int n = p.length();
    int **ar = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        ar[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            ar[i][j] = -1;
        }
    }
    return isMatch(s, p, ar, m, n);
}
};