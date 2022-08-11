class Solution {
public:
    bool kLengthApart(vector<int>& ar, int k) {
        int prev = -1;
        int n = ar.size();
        for(int i = 0 ; i < n ; i++){
            if(ar[i] == 1){
                if(prev == -1){
                    prev = i;
                }
                else if(i - prev - 1 < k){
                    return false;
                }
                else{
                    prev = i;
                }
            }
        }
        return true;
    }
};