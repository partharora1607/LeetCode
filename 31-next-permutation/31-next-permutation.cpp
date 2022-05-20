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
            // swap with just greater number than ar[i-1];
            for (int j = i; j < n; j++)
            {
                if (ar[j] > ar[i - 1])
                {
                    val = min(ar[j] , val);
                    index = j;
                }
            }
            swap(ar[i - 1], ar[index]);
            // sort the last part of it.             
            reverse(ar.begin() + i, ar.end());
            return;
        }
    }
    reverse(ar.begin(),ar.end());
}
};