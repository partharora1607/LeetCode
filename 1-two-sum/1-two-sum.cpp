class Solution {
public:
    vector<int> twoSum(vector<int> &ar, int target)
{
    unordered_map<int, int> mymap;
    for (int i = 0; i < ar.size(); i++)
    {
        if (mymap.find(target - ar[i]) != mymap.end())
        {
            return {mymap[target - ar[i]], i};
        }
        mymap[ar[i]] = i;
    }
    return {};
}
};