class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &ar)
{
    if (ar.size() <= 2)
    {
        return {};
    }
    sort(ar.begin(), ar.end());
    int n = ar.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n - 2; i++)
    {
        if(i > 0 && ar[i] == ar[i - 1])
        {
            continue;
        }
        int si = i + 1;
        int ei = n - 1;
        while (si < ei)
        {
            if (ar[i] + ar[si] + ar[ei] == 0)
            {
                ans.push_back({ar[i], ar[si], ar[ei]});
                ei--;
                while (si < ei && ar[ei] == ar[ei + 1])
                {
                    ei--;
                }
            }
            else if (ar[i] + ar[si] + ar[ei] > 0)
            {
                ei--;
            }
            else
            {
                si++;
            }
        }
    }
    return ans;
}
};