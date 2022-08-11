class Solution {
public:
    int helper(vector<int> &ar, int si, int ei, vector<int> &output)
{
    if (si > ei)
    {
        return 0;
    }

    if (si == ei)
    {
        return ar[si];
    }

    if (output[si] != -1)
    {
        return output[si];
    }

    int op1 = helper(ar, si + 1, ei, output) + ar[si];
    int op2 = helper(ar, si + 2, ei, output) + ar[si];

    return output[si] = min(op1, op2);
}

int minCostClimbingStairs(vector<int> &ar)
{
    int n = ar.size();
    vector<int> output(n + 1, -1);
    int op1 = helper(ar, 0, n - 1, output);
    int op2 = helper(ar, 1, n - 1, output);

    return min(op1, op2);
}
};