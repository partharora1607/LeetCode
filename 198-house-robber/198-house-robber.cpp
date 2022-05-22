class Solution {
public:
    int rob(vector<int> &ar)
{
    int n = ar.size();
    int *output = new int[n + 1];
    output[0] = 0;
    output[1] = ar[n - 1];
    for (int i = 2; i <= n; i++)
    {
        output[i] = max(output[i - 1], output[i - 2] + ar[n - i]);
    }
    return output[n];
}
};