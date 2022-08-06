class Solution {
public:
    int helper(vector<int> &ar, int si, int ei, int m, vector<vector<int>> &output)
{
    if (si > ei)
    {
        return 0;
    }

    if (output[si][m] != -1)
    {
        return output[si][m];
    }

    if (m == 1)
    {
        int sum = 0;
        for (int i = si; i <= ei; i++)
        {
            sum += ar[i];
        }
        output[si][m] = sum;
        return output[si][m];
    }

    int sum = 0;
    int ans = INT_MAX;

    for (int i = si + 1; i <= ei; i++)
    {
        sum += ar[i - 1];
        int smallans = helper(ar, i, ei, m - 1, output);
        ans = min(ans, max(smallans, sum));
    }
    output[si][m] = ans;
    return ans;
}

int splitArray(vector<int> &ar, int m)
{
    int n = ar.size();
    vector<vector<int>> output(n + 1, vector<int>(m + 1, -1));
    return helper(ar, 0, n - 1, m, output);
}
};