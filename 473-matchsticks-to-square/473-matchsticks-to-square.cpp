class Solution {
public:
bool helper(vector<int> &ar, int si, int ei, int sum_1, int sum_2, int sum_3, int sum_4, int target)
{
    if (si > ei)
    {
        if (sum_1 == target && sum_2 == target && sum_3 == target && sum_4 == target)
        {
            return true;
        }
        return false;
    }

    if(sum_1 > target || sum_2 > target || sum_3 > target || sum_4 > target){
        return false;
    }

    bool op1 = helper(ar, si + 1, ei, sum_1 + ar[si], sum_2, sum_3, sum_4, target);
    bool op2 = helper(ar, si + 1, ei, sum_1, sum_2 + ar[si], sum_3, sum_4, target);
    bool op3 = helper(ar, si + 1, ei, sum_1, sum_2, sum_3 + ar[si], sum_4, target);
    bool op4 = helper(ar, si + 1, ei, sum_1, sum_2, sum_3, sum_4 + ar[si], target);

    return op1 || op2 || op3 || op4;
}

bool makesquare(vector<int> &ar)
{
    int n = ar.size();
    int totalsum = accumulate(ar.begin(), ar.end(), 0);
    sort(ar.begin() , ar.end() , greater<int>());
    if (totalsum % 4 != 0)
    {
        return false;
    }
    int target = totalsum / 4;
    return helper(ar, 0, n - 1, 0, 0, 0, 0, target);
}
};