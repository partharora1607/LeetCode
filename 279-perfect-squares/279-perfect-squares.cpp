class Solution {
public:
int helper(int n, vector<int> &output)
{
    if (n <= 3)
    {
        return n;
    }

    if (output[n] != -1)
    {
        return output[n];
    }

    int i = 1;
    int ans = pow(10, 5);

    while (i * i <= n)
    {
        int smallans = helper(n - (i * i), output) + 1;
        ans = min(ans, smallans);
        i++;
    }
    output[n] = ans;
    return ans;
}
int numSquares(int n)
{
    vector<int> output(n + 1, -1);
    return helper(n, output);
}
};