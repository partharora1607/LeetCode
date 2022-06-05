class Solution {
public:
    int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int maxans = 0;
    int maxafter = prices[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        int ans = maxafter - prices[i];
        maxafter = max(maxafter, prices[i]);
        maxans = max(maxans, ans);
    }
    return maxans;
}

};