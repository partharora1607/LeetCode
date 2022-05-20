class Solution {
public:
vector<int> twoSum(vector<int> &ar, int target)
{
    vector<int> ans;
    unordered_map<int, int> mymap;
    for (int i = 0; i < ar.size(); i++)
    {
        if (mymap.count(target - ar[i]) > 0)
        {
            ans.push_back(mymap[target - ar[i]]);
            ans.push_back(i);
            return ans;
        }
        mymap[ar[i]] = i;
    }
    return ans;
}
};