class Solution {
public:
vector<vector<int>> insert(vector<vector<int>> &v, vector<int> &newInterval)
{
    vector<vector<int>> res;
    int i = 0;
    while (i < v.size() && newInterval[0] > v[i][1])
    {
        res.push_back(v[i++]);
    }
    while (i < v.size() && newInterval[1] >= v[i][0])
    {
        newInterval[0] = min(newInterval[0], v[i][0]);
        newInterval[1] = max(newInterval[1], v[i][1]);
        i++;
    }
    res.push_back(newInterval);
    while (i < v.size())
    {
        res.push_back(v[i++]);
    }
    return res;
}
};