class Solution {
public:
    bool canJump(vector<int> &ar)
{
    int goal = ar.size() - 1;
    for (int i = goal - 1; i >= 0; i--)
    {
        if (goal - i <= ar[i])
        {
            goal = i;
        }
    }
    return goal == 0;
}
};