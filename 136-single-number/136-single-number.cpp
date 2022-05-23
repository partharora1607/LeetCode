class Solution {
public:
    int singleNumber(vector<int>& ar) {
        int ans = ar[0];
        for (int i = 1; i < ar.size() ; i++)
        {   
            ans ^= ar[i];
        }
        return ans;
    }
};