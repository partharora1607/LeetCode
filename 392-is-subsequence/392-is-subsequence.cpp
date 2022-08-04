class Solution {
public:
bool helper(string s, string t, int m, int n, vector<vector<int>> &output)
{
    if (m == 0)
    {
        return true;
    }

    if (m > n)
    {
        return false;
    }

    if (output[m][n] != -1)
    {
        return output[m][n];
    }

    if (s[0] == t[0])
    {
        output[m][n] = helper(s.substr(1), t.substr(1), m - 1, n - 1, output);
        return output[m][n];
    }

    output[m][n] = helper(s , t.substr(1) , m , n - 1 , output);
    return output[m][n];

}

bool isSubsequence(string s, string t)
{
    int m = s.length();
    int n = t.length();
    vector<vector<int>> output(m + 1, vector<int>(n + 1, -1));
    return helper(s, t, m, n, output);
}
};