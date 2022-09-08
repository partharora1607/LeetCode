class Solution {
public:
    int getMinDistance(vector<int>& ar, int target, int start) {
        if(ar[start] == target){
            return 0;
        }
        int n = ar.size();
        int rs = INT_MAX, ls = INT_MAX;
        for(int i = start + 1; i < n ; i++){
            if(ar[i] == target){
                rs = i;
                break;
            }
        }
        for(int i = start - 1 ; i >= 0 ; i--){
            if(ar[i] == target){
                ls = i;
                break;
            }
        }
        return min(abs(start - ls) , abs(start - rs));
        
    }
};