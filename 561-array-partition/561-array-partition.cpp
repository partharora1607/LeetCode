class Solution {
public:
    int arrayPairSum(vector<int>& ar) {
        sort(ar.begin(),ar.end());
        int n = ar.size();
        int ans = 0;
        for(int  i = 0 ; i < n;i+=2){
            ans += ar[i];
        }
        return ans;
    }
};