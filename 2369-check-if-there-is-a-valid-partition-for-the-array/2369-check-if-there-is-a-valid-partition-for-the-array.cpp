class Solution {
public:
  
bool helper(vector<int> &ar, int si, int ei, vector<int> &output)
{
    if (si > ei)
    {
        return true;
    }
    if (output[si] != -1)
    {
        return output[si];
    }
    if (si + 1 < ar.size() && ar[si] == ar[si + 1])
    {
        if (helper(ar, si + 2, ei, output))
        {
            output[si] = true;
            return true;
        }
    }
    if (si + 2 < ar.size())
    {
        if (ar[si] == ar[si + 1] - 1 && ar[si] == ar[si + 2] - 2 && helper(ar, si + 3, ei, output))
        {
            output[si] = true;
            return true;
        }
        if ((ar[si] == ar[si + 2] && ar[si] == ar[si + 1]) && helper(ar, si + 3, ei, output))
        {
            output[si] = true;
            return true;
        }
    }
    return output[si] = false;
}
bool validPartition(vector<int> &ar)
{
    int n = ar.size();
    vector<int> output(n + 1, -1);
    return helper(ar, 0, n - 1, output);
}
};