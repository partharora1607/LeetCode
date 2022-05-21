class Solution {
public:
int searchInsert(vector<int> &ar, int target)
{
    int i = 0, j = ar.size() - 1, mid;
    while (i <= j)
    {
        mid = i + (j - i) / 2;
        if (ar[mid] == target)
        {
            return mid;
        }
        else if (target > ar[mid])
        {
            i = mid + 1; // move right
        }
        else
        {
            j = mid - 1; // move left
        }
    }
    if (j < 0)
    {
        return 0;
    }
    else if (i >= ar.size())
    {
        return i;
    }
    else if (target > ar[i])
    {
        return i + 1;
    }
    return i;
}
};