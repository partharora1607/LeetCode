class Solution {
public:
int maxProfit(vector<int> &ar)
{
    int n = ar.size();
    if(n <= 1){
        return 0;
    }
    vector<int> res(n);
    int min_so_far = ar[0];
    res[0] = 0;

    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        res[i] = max(ar[i] - min_so_far , 0);
        min_so_far = min(min_so_far , ar[i]);
        ans = max(ans , res[i]);
    }
    return ans;
}
};