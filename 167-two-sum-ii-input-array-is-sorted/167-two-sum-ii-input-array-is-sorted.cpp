class Solution {
public:
vector<int> res;

vector<int> twoSum(vector<int> &ar, int target)
{
    int i = 0, j = ar.size() - 1;
    while (i < j)
    {
        if (ar[i] + ar[j] == target)
        {
            res.push_back(i + 1);
            res.push_back(j + 1);
            return res;
        }
        else if (ar[i] + ar[j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return res;
}
};