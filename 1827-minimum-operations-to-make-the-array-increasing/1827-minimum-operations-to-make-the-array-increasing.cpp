class Solution {
public:
    int minOperations(vector<int>& ar) {
        int n  =ar.size();
        if(n == 1){
            return 0;
        }
        int ans = 0;
        for(int i = 1 ; i < n ; i++){
            if(ar[i] > ar[i - 1]){
                continue;
                
            }
            else{
                ans += ar[i - 1] - ar[i] + 1;
                ar[i] = ar[i -1] + 1;
            }
        }
        return ans;
    }
};