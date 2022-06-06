class Solution {
public:
    int helper(int n, int *ar)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    if (ar[n] != -1)
    {
        return ar[n];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += helper(i - 1, ar) * helper(n - i, ar);
    }
    ar[n] = ans;
    return ar[n];
}

int numTrees(int n)
{
    int *ar = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ar[i] = -1;
    }
    // ar[i] = ans from i no of nodes
    return helper(n, ar);
}
};