class Solution {
public:
void nextPermutation(vector<int> &ar)
{
    int n = ar.size();
    int val = INT_MAX;
    int index;
    for (int i = n - 1; i > 0; i--)
    {
        if (ar[i] > ar[i - 1])
        {
            for (int j = i; j < n; j++)
            {
                if (ar[j] > ar[i - 1])
                {
                    val = min(ar[j], val);
                    index = j;
                }
            }
            swap(ar[i - 1], ar[index]);
            sort(ar.begin() + i, ar.end());
            return;
        }
    }
    sort(ar.begin(), ar.end());
}
};