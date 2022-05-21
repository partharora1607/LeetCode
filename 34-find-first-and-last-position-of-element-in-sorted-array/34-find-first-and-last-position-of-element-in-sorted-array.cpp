class Solution {
public:
    int position(vector<int> &ar, int sp, int ep, int target)
{
    int i = 0, j = ar.size() - 1, mid;
    while (i <= j)
    {
        mid = i + (j - i) / 2;
        if (ep == 0)
        {
            // we have to find the starting position
            if (ar[mid] == target)
            {
                if (mid - 1 >= 0 && ar[mid - 1] == ar[mid])
                {
                    j = mid - 1; // move more left
                }
                else
                {
                    return mid; // return mid
                }
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
            // we have to find the end position
            if (ar[mid] == target)
            {
                if (mid + 1 < ar.size() && ar[mid + 1] == ar[mid])
                {
                    i = mid + 1; // move right
                }
                else
                {
                    return mid;
                }
            }
            else if (target > ar[mid])
            {
                i = mid + 1; // move right
            }
            else
            {
                j = mid - 1;
                // move left
            }
        }
    }
    return -1;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int sp = position(nums, -1, 0, target);
    int ep = position(nums, 0, -1, target);
    return {sp, ep};
}
};