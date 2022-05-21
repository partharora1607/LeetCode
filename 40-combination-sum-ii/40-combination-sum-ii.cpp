class Solution {
public:
void helper(vector<int> &ar, int si, int ei, int target, int sum, vector<int> &ans, vector<vector<int>> &v)
{
    if (si > ei)
    {
        if (sum == target)
        {
            v.push_back(ans);
            return;
        }
        return;
    }

    if (sum > target)
    {
        return;
    }

    if (sum == target)
    {
        v.push_back(ans);
        return;
    }

    for (int i = si; i <= ei; i++)
    {
        if (i == si)
        {
            ans.push_back(ar[si]);
            helper(ar, si + 1, ei, target, sum + ar[si], ans, v);
            ans.pop_back();
        }
        else if (ar[i] != ar[i - 1])
        {
            helper(ar, i, ei, target, sum, ans, v);
            break;
        }
    }
}

vector<vector<int>> combinationSum2(vector<int> &ar, int target)
{
    vector<int> ans;
    vector<vector<int>> v;
    sort(ar.begin(), ar.end());
    helper(ar, 0, ar.size() - 1, target, 0, ans, v);
    return v;
}
};