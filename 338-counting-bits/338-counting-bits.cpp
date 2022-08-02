class Solution {
public:
    int convert_count(int n)
{
    int i = n;
    int count = 0;
    while (i > 0)
    {
        int val = i % 2;
        if (val == 1)
        {
            count++;
        }
        i /= 2;
    }
    return count;
}

vector<int> countBits(int n)
{
    if (n == 0)
        return {0};
    vector<int> res;
    for (int i = 0; i <= n; i++)
    {
        int smallans = convert_count(i);
        res.push_back(smallans);
    }
    return res;
}
};