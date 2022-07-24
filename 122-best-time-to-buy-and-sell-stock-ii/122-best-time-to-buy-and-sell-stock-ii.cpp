class Solution {
public:
    int maxProfit(vector<int>& ar) {
        int n = ar.size();
        if(n <= 1){
            return 0;
        }
        
        int ans = 0;
        
        for(int i = 1 ; i < n ; i++){
            if(ar[i] > ar[i - 1]){
                ans += ar[i] - ar[i - 1];
            }
        }
        
        return ans;
        
    }
};