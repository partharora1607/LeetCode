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
        int new_target = target - ar[i];
        while (si < ei)
        {
            sum = ar[si] + ar[ei];
            if (sum == new_target)
            {
                return sum + ar[i];
            }
            else if (sum > new_target)
            {
                if (abs(new_target - sum) < closestsum)
                {
                    closestsum = abs(new_target - sum);
                    ans = sum + ar[i];
                }
                ei--;
            }
            else
            {
                if (abs(new_target - sum) < closestsum)
                {
                    closestsum = abs(new_target - sum);
                    ans = sum + ar[i]; 
                }
                si++;
            }
        }
    }
    return ans;
}
};