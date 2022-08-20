class Solution {
public:
    int getMaximumGenerated(int n)
{
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    vector<int> ar(n + 1);
    ar[0] = 0;
    ar[1] = 1;
    if (n % 2 != 0)
    {
        for (int i = 1; i <= n / 2; i++)
        {
            ar[2 * i] = ar[i];
            ar[2 * i + 1] = ar[i] + ar[i + 1];
        }
        return *max_element(ar.begin(), ar.end());
    }
    for (int i = 1; i < n / 2; i++)
    {
        ar[2 * i] = ar[i];
        ar[2 * i + 1] = ar[i] + ar[i + 1];
    }
    return *max_element(ar.begin(), ar.end());
}
};