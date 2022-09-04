class Solution {
public:
    void duplicateZeros(vector<int>& ar) {
        int index = 0;
        int n = ar.size();
        vector<int> dp(n);
        int j = 0;
        for(int i = 0 ; j < n && i < n ; i++){
            if(ar[i] == 0){
                dp[j++] = 0;
                if(j < n){
                    dp[j++] = 0;
                }
            }
            else{
                dp[j++] = ar[i];
            }
        }
        for(int i = 0; i < n ;i++){
            ar[i] = dp[i];
        }
    }
};