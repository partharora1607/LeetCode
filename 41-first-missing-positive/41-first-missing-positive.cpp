class Solution {
public:
    int firstMissingPositive(vector<int> &ar)
{
    int n = ar.size();

    for (int i = 0; i < ar.size(); i++)
    {
        if (ar[i] <= 0)
        {
            ar[i] = n + 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int index = abs(ar[i]) - 1;
        if ((index >= 0 && index < n) && ar[index] > 0)
        {
            ar[index] *= -1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (ar[i - 1] > 0)
        {
            return i;
        }
    }
    return n + 1;
}
};