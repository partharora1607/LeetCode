class Solution {
public:
    bool kLengthApart(vector<int>& ar, int k) {
        int i = 0;       
        int n = ar.size();
        for(i =0;i < n ;i++){
            if(ar[i] == 1){
                break;
            }
        }
        if(i == n){
            return true;
        }
        int prev = i;
        for(int j = i + 1 ; j < n ; j++){
            if(ar[j] == 1){
                if(j - prev - 1 < k){
                    return false;
                }
                else{
                    prev = j;
                }
            }
        }
        return true;
    }
};