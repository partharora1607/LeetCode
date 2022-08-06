class Solution {
public:
int helper(vector<int> &ar, int si, int ei)
{
    int n = ar.size();
    vector<int> output(n - 1, -1);
    for (int i = 0; i < n - 1; i++)
    {
        output[i] = ar[i + 1] - ar[i];
    }
    int ans = 0;

    int i = 0;
    int count = 0;
    int m = output.size();
    while (i < m)
    {
        count = 1;
        while (i < m - 1 && output[i] == output[i + 1])
        {
            count++;
            i++;
        }
        if (count >= 2)
        {
            ans += ((count - 1) * (count)) / 2;
        }
        i++;
    }
    return ans;
}

int numberOfArithmeticSlices(vector<int> &ar)
{
    int n = ar.size();
    if (n < 3)
    {
        return 0;
    }
    return helper(ar, 0, n - 1);
}
};