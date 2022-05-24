class Solution {
public:
    vector<int> getRow(int n)
{
     n += 1;
    vector<vector<int>> v;
    v.push_back({1});
    if (n == 1)
    {
        return v[0];
    }
    v.push_back({1, 1});
    if (n == 2)
    {
        return v[1];
    }
    for (int i = 0; i < n - 2; i++)
    {
        int n = v[i + 1].size();
        int f = 0;
        int s = 1;
        vector<int> ans;
        ans.push_back(1);
        while (f < n - 1)
        {
            int sum = v[i + 1][f] + v[i + 1][s];
            ans.push_back(sum);
            f++;
            s++;
        }
        ans.push_back(1);
        v.push_back(ans);
    }
    return v[n - 1];
}
};