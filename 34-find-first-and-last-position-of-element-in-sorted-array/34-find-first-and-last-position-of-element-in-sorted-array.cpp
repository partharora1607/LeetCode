class Solution {
public:
    int position(vector<int> &ar, int ep, int target)
{
    int i = 0, j = ar.size() - 1, mid;
    int ans = -1; // this will tell me the possible ans of positions
    while (i <= j)
    {
        mid = i + (j - i) / 2;
        if (ep == 0)
        {
            // find the stating position
            if (ar[mid] == target)
            {
                ans = mid;
                j = mid - 1; // move left
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
        else
        {
            // find the ending positions
            if (ar[mid] == target)
            {
                ans = mid;
                i = mid + 1; // move right
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
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int sp = position(nums, 0, target);
    int ep = position(nums, -1, target);
    return {sp, ep};
}
};