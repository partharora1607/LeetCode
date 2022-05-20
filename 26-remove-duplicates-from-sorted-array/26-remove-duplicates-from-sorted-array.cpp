class Solution {
public:
    int removeDuplicates(vector<int> &ar)
{
    int index = 1;
    for (int i = 1; i < ar.size(); i++)
    {
        if (ar[i] != ar[i - 1])
        {
            ar[index++] = ar[i];
        }
    }
    return index;
}
};