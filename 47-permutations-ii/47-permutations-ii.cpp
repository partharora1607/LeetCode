class Solution {
public:
void helper(vector<int> &ar, int si, int ei, vector<int> &ans, vector<vector<int>> &v, set<vector<int>> &s1)
{
    // base case
    if (ans.size() == ar.size())
    {
        if (s1.count(ans) == 0)
        {
            s1.insert(ans);
            v.push_back(ans);
            return;
        }
    }

    for (int i = si; i <= ei; i++)
    {
        if (i != si && ar[i] == ar[i - 1])
        {
            continue;
        }
        swap(ar[si], ar[i]);
        ans.push_back(ar[si]);
        helper(ar, si + 1, ei, ans, v, s1);
        ans.pop_back();
        swap(ar[si], ar[i]);
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<int> ans;
    vector<vector<int>> v;
    set<vector<int>> s1;
    helper(nums , 0 , nums.size() - 1 , ans , v , s1);
    return v;
}
};