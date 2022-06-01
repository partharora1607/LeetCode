class Solution {
public:
    vector<int> runningSum(vector<int> &ar)
{
    for (int i = 1; i < ar.size(); i++)
    {
        ar[i] += ar[i - 1];
    }
    return ar;
}
};