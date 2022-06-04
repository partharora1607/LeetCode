class Solution {
public:
 vector<vector<int>> insert(vector<vector<int>> &v, vector<int> &newInterval)
{
    vector<vector<int>> res;
    int index = 0;
    while (index < v.size() && v[index][1] < newInterval[0])
    {
        res.push_back(v[index++]);
    }
    while (index < v.size() && v[index][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], v[index][0]);
        newInterval[1] = max(newInterval[1], v[index][1]);
        index++;
    }
    res.push_back(newInterval);
    while (index < v.size())
    {
        res.push_back(v[index++]);
    }
    return res;
}
};