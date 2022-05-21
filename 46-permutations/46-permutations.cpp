class Solution {
public:
    
void helper(vector<int> &ar, int si, int ei, vector<int> &ans, vector<vector<int>> &v)
{
    if (ans.size() == ar.size())
    {
        v.push_back(ans);
        return;
    }

    for (int i = si; i <= ei; i++)
    {
        swap(ar[si], ar[i]);
        ans.push_back(ar[si]);
        helper(ar, si + 1, ei, ans, v);
        swap(ar[si], ar[i]);
        ans.pop_back();
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> ans;
    vector<vector<int>> v;
    helper(nums, 0, nums.size() - 1, ans, v);
    return v;
}
};