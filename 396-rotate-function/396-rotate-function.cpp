class Solution {
public:

int maxRotateFunction(vector<int> &ar)
{
    int n = ar.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += ar[i];
    }
    int var = 0;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        var = var + (k * ar[i]);
        k++;
    }
    int ans = var;
    for (int i = 1; i < n; i++)
    {
        int smallans = var + sum - n * (ar[n - i]);
        var = smallans;
        ans = max(ans, smallans);
    }
    return ans;
}
};