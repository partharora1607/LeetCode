class Solution {
public:
int searchInsert(vector<int> &ar, int target)
{
    int i = 0, j = ar.size() - 1, mid, ans = -1;
    /* ans will tell me the possible index */
    while (i <= j)
    {
        mid = i + (j - i) / 2;
        if (ar[mid] == target)
        {
            return mid;
        }
        else if (target > ar[mid])
        {
            ans = mid + 1; // possible ans can be just next index
            i = mid + 1;   // move right
        }
        else
        {
            ans = mid;   // possible ans can be the same index
            j = mid - 1; // move left
        }
    }
    return ans;
}
};