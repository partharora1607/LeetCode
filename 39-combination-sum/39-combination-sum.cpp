class Solution {
public:
    void helper(vector<int> &ar, int si, int ei, vector<int> &ans, int target, int sum, vector<vector<int>>& v)
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
    if (sum == target)
    {
        v.push_back(ans);
        return;
    }
    if (sum > target)
    {
        return;
    }
    // not include the element
    helper(ar, si + 1, ei, ans, target, sum, v);
    // include
    ans.push_back(ar[si]);
    helper(ar, si, ei, ans, target, sum + ar[si], v);
    ans.pop_back();// as ans is a global variable
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> ans;
    vector<vector<int>> v;
    helper(candidates, 0, candidates.size() - 1, ans, target, 0, v);
    return v;
}
};