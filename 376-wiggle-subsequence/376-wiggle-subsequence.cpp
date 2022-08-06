class Solution {
public:
int wiggleMaxLength(vector<int> &ar)
{    int n = ar.size();

    if (n == 1)
    {
        return 1;
    }
     int i = 1;
    int count = 1;
    while (i < n && ar[i] - ar[i - 1] == 0)
    {
        i++;
    }
    if (i == n)
    {
        return count;
    }
    if (n == 2)
    {
        return 2;
    }

    int prev = ar[i] - ar[i - 1];
    i++;
    while (i < n)
    {
        if (ar[i] - ar[i - 1] > 0 && prev < 0)
        {
            prev = 1;
            count++;
        }
        else if (ar[i] - ar[i - 1] < 0 && prev > 0)
        {
            prev = -1;
            count++;
        }
        i++;
    }
    return count + 1;
}
};