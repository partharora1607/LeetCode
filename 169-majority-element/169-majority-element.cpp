class Solution {
public:
    int majorityElement(vector<int> &ar)
{
    int ele = ar[0];
    int count = 1;
    for (int i = 1; i < ar.size(); i++)
    {
        if (count == 0)
        {
            ele = ar[i];
            count = 1;
        }
        else if (ar[i] == ele)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return ele;
}
};