class Solution {
public:
    vector<int> shuffle(vector<int>& ar, int n) {
        vector<int> ans(2*n);
        int i = 0 , j = n;
        int c = 0;
        while(j < 2*n && i < n){
            ans[c++] = ar[i++];
            ans[c++] = ar[j++];
        }
        return ans;
    }
};