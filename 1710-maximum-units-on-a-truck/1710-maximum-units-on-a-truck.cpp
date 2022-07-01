class Solution {
public:
int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
{
    priority_queue<pair<int, int>> pq; // inbuild greater function of pq
    for (int i = 0; i < boxTypes.size(); i++)
    {
        int f = boxTypes[i][0];
        int s = boxTypes[i][1];
        pq.push({s, f});
    }
    
    int res = 0;

    while (truckSize > 0 && !pq.empty())
    {
        pair<int, int> temp = pq.top();
        pq.pop();

        int freq = temp.second;
        int val = temp.first;

        if (truckSize - freq >= 0)
        {
            res += freq * val;
            truckSize -= freq;
        }
        else
        {
            res += truckSize * val;
            truckSize = 0;
        }

    }

    return res;
}
};