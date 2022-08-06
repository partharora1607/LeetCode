class Solution {
public:
bool helper(vector<int> &ar , int si , int ei , int k, vector<vector<int>> &output)
{
    if(si >= ei)
    {
        return true;
    }

    if(output[si][k] != -1){
        return output[si][k];
    } 

    int op1 = k - 1 + ar[si];
    int op2 = k + ar[si];
    int op3 = k + 1 + ar[si];

    for (int i = si + 1; i <= ei; i++)
    {
        if (ar[i] > op3)
        {
            break;
        }
        if (ar[i] == op1 && helper(ar, i, ei, k - 1 , output))
        {
            output[si][k] = true;
            return true;
        }
        if (ar[i] == op2 && helper(ar, i, ei, k , output))
        {
            output[si][k] = true;
            return true;
        }
        if (ar[i] == op3 && helper(ar, i, ei, k + 1 , output))
        {
            output[si][k] = true;
            return true;
        }
    }
    output[si][k] =  false;
    return false;

}

bool canCross(vector<int> &ar)
{
    int n = ar.size();
    if (ar[1] != ar[0] + 1)
    {
        return false;
    }
    int k = 2;
    for (int i = 1; i < n; i += k)
    {
        k++;
    }
    vector<vector<int>> output(n + 1, vector<int>(n + 1 , -1));
    return helper(ar , 1 , n - 1 , 1 , output);
}
};