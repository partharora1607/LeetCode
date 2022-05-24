class Solution {
public:
    vector<int> getRow(int n)
{
    vector<int> ar(n + 1, 0);
    ar[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            ar[j] += ar[j - 1];
        }
    }
    return ar;
}
};