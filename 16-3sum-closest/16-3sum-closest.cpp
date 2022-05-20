class Solution {
public:
int threeSumClosest(vector<int> &ar, int target)
{
    int closestsum = INT_MAX;
    int ans = 0;
    sort(ar.begin(), ar.end());
    int si, ei;
    int n = ar.size();
    for (int i = 0; i < n - 2; i++)
    {
        si = i + 1, ei = n - 1;
        int sum;
        while (si < ei)
        {
            sum = ar[i] + ar[si] + ar[ei];
            if (sum == target)
            {
                return sum;
            }
            else if (sum > target)
            {
                if (abs(target - sum) < closestsum)
                {
                    closestsum = abs(target - sum);
                    ans = sum;
                }
                ei--;
            }
            else
            {
                if (abs(target - sum) < closestsum)
                {
                    closestsum = abs(target - sum);
                    ans = sum;
                }
                si++;
            }
        }
    }
    return ans;
}
};