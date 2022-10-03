class Solution {
public:
    int minimumCost(vector<int>& ar) {
        sort(ar.begin() , ar.end());
        int ans =0 ;
        int n = ar.size();
        for(int i = n - 1 ; i >= 0 ;){
            if(i > 1){
                ans += ar[i] + ar[i - 1];
                i-=3;
            }
            else if(i <= 1){
                ans += ar[i];
                i--;
            }
        }
        return ans;
    }
};