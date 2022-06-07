class Solution {
public:
        void merge(vector<int> &ar1, int m, vector<int> &ar2, int n)
{
    int i = 0;
    int j = 0;
    vector<int> v;
    while (i < m && j < n)
    {
        if (ar1[i] < ar2[j])
        {
            v.push_back(ar1[i]);
            i++;
        }
        else
        {
            v.push_back(ar2[j]);
            j++;
        }
    }
    while (i < m)
    {
        v.push_back(ar1[i++]);
    }
    while (j < n)
    {
        v.push_back(ar2[j++]);
    }
    for (int i = 0; i < v.size(); i++)
    {
        ar1[i] = v[i];
    }
}
};