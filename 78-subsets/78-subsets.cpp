class Solution {
public:
vector<vector<int>> helper_2(vector<int> &ar, int si, int ei)
{
    if (si > ei)
    {
        return {{}};
    }

    vector<vector<int>> v = helper_2(ar, si + 1, ei);

    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        vector<int> ans;
        ans.push_back(ar[si]);
        for (int j = 0; j < v[i].size(); j++)
        {
            ans.push_back(v[i][j]);
        }
        v.push_back(ans);
        ans.clear();
    }

    return v;
}

vector<vector<int>> subsets(vector<int> &ar)
{
    return helper_2(ar, 0, ar.size() - 1);
}
};