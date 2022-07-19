class Solution {
public:
int jump(vector<int> &ar, int si, int ei, vector<int> &output)
{
    if (si >= ei)
    {
        return 0;
    }

    int n = ei - si + 1;

    if (output[n] != -1)
    {
        return output[n];
    }

    int ans = pow(10, 5);

    for (int i = 1; i <= ar[si]; i++)
    {
        int ans1 = jump(ar, si + i, ei, output) + 1;
        ans = min(ans1, ans);
    }
    output[n] = ans;
    return ans;
}

int jump(vector<int> &ar)
{
    int n = ar.size();
    vector<int> output(n + 1, -1);
    return jump(ar, 0, ar.size() - 1, output);
}
};