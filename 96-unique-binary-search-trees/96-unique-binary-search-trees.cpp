class Solution {
public:
    int numTrees(int n)
{
    if (n <= 2)
    {
        return n;
    }
    int *ar = new int[n + 1];
    ar[0] = 1;
    ar[1] = 1;
    ar[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        // i - curr size;
        int ans = 0;
        for (int j = 1; j <= i; j++)
        {
            // j - iterator
            ans += ar[j - 1] * ar[i - j];
        }
        ar[i] = ans;
    }
    return ar[n];
}
};