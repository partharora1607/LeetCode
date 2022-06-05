class Solution {
public:
    int maxProfit(vector<int> &ar)
{
    if (ar.size() == 1)
    {
        return 0;
    }
    int buy = 0, sell = 1;
    int profit = 0;
    while (sell < ar.size())
    {
        if (ar[buy] > ar[sell])
        {
            buy = sell;
        }
        else
        {
            profit = max(profit, ar[sell] - ar[buy]);
        }
        sell++;
    }
    return profit;
}
};