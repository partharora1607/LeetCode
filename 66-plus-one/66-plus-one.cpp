class Solution {
public:
    vector<int> plusOne(vector<int> &ar)
{
    int n = ar.size();
    if (ar[n - 1] < 9)
    {
        ar[n - 1] = ar[n - 1] + 1;
        return ar;
    }
    int carry = 1,i=n-1;
    while (i >= 0)
    {
        int sum = ar[i] + carry;
        carry = sum / 10;
        ar[i] = sum % 10;
        i--;
    }
    if (carry > 0)
    {
        vector<int> v;
        v.push_back(carry);
        for (int i = 0; i < ar.size(); i++)
        {
            v.push_back(ar[i]);
        }
        return v;
    }
    return ar;
}
};