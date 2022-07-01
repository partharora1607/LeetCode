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

    int count = 0;
    while (count < truckSize && !pq.empty())
    {
        pair<int, int> c = pq.top();
        pq.pop();
        int val = c.first;
        int freq = c.second;
        if (count + freq <= truckSize)
        {
            res += freq * val;
            count += freq;
        }
        else
        {
            freq = truckSize - count;
            res += val * freq;
            count += freq;
        }
    }
    return res;
}
};