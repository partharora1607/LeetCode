class Solution {
public:
int maxProfit(vector<int> &ar)
{
    if (ar.size() == 1)
    {
        return 0;
    }
    int i = 0, j = 1;
    // i = buy
    // j = sell
    int ans = 0;
    int currans = 0;
    while (j < ar.size())
    {
        if (ar[i] > ar[j]) // buy > sell
        {
            i = j; // buy = sell;
        }
        else
        {
            ans = max(ans, ar[j] - ar[i]); // sell - buy
        }
        j++;
    }
    return ans;
}


};