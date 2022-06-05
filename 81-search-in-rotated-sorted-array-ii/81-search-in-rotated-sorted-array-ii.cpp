class Solution {
public:
    bool isBinarySearchHelpful(vector<int> &ar, int i, int target)
{
    return ar[i] != target;
}

bool search(vector<int> &ar, int target)
{
    int n = ar.size();
    if (n == 0)
    {
        return false;
    }
    int i = 0, j = n - 1;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (ar[mid] == target)
        {
            return true;
        }

        if (!isBinarySearchHelpful(ar, i, ar[mid]))
        {
            i++;
            continue;
        }

        else if (ar[mid] > ar[i])
        {
            // left part is sorted
            if (target >= ar[i] && target < ar[mid])
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        else
        {
            // right part is sorted
            if (target > ar[mid] && target <= ar[j])
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
    }
    return false;
}
};