class Solution {
public:
void helper(vector<int> &ar, int si, int ei, set<vector<int>> &s1, vector<int> &ans, vector<vector<int>> &v)
{
    if (si > ei)
    {
        if (s1.count(ans) == 0)
        {
            s1.insert(ans);
            v.push_back(ans);
            return;
        }
        return;
    }
    helper(ar, si + 1, ei, s1, ans, v);
    ans.push_back(ar[si]);
    helper(ar, si + 1, ei, s1, ans, v);
    ans.pop_back();
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    set<vector<int>> s1;
    sort(nums.begin(), nums.end());
    vector<int> ans;
    vector<vector<int>> v;
    helper(nums, 0, nums.size() - 1, s1, ans, v);
    return v;
}
};