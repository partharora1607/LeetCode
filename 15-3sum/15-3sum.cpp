class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &ar)
{
    if (ar.size() <= 2)
    {
        return {};
    }
    sort(ar.begin(), ar.end());
    int ei = ar.size() - 1;
    int si;
    vector<vector<int>> ans;
    for (int i = 0; i < ar.size() - 2; i++)
    {
        // remove duplicates from left side         
        if(i > 0 && ar[i] == ar[i - 1])
        {
            continue;
        }
        si = i + 1;
        ei = ar.size() - 1;
        while (si < ei)
        {
            if (ar[i] + ar[si] + ar[ei] == 0)
            {
                ans.push_back({ar[i], ar[si], ar[ei]});
                ei--;
                // remove duplicated from right side                 
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