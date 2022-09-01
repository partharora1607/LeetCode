class Solution {
public:
    int findGCD(vector<int>& ar) {
        int mini = INT_MAX , maxi = INT_MIN;
        int n = ar.size();
        for(int i = 0 ;i < n;i ++){
            if(ar[i] < mini){
                mini = ar[i];
            }
            if(ar[i] > maxi){
                maxi = ar[i];
            }
        }
        
        int val = mini;
        while(val > 0){
            if(mini % val == 0 && maxi % val == 0){
                return val;
            }
            val--;
        }
        return 1;
        
    }
};