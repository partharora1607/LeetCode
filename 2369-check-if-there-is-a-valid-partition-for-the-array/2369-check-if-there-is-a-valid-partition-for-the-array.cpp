class Solution {
public:
  
bool helper(vector<int> &ar, int i, vector<int> &output)
{
    if (i == ar.size())
    {
        return true;
    }
    if (output[i] != -1)
    {
        return output[i];
    }

    if (i + 1 < ar.size() && ar[i] == ar[i + 1])
    {
        if (helper(ar, i + 2, output))
        {
            return true;
        }
        if (i + 2 < ar.size() && ar[i] == ar[i + 2])
        {
            if (helper(ar, i + 3, output))
            {
                return true;
            }
        }
    }
    if (i + 2 < ar.size() && ar[i] == ar[i + 1] - 1 && ar[i] == ar[i + 2] - 2)
    {
        if (helper(ar, i + 3, output))
        {
            return true;
        }
    }
    return output[i] = false;
}
bool validPartition(vector<int> &ar)
{
    int n = ar.size();
    vector<int> output(n, -1);
    return helper(ar, 0, output);
}
};