class Solution {
public:
    bool isMonotonic(vector<int>& ar) {
        int n = ar.size();
        if(n <= 1){
            return true;
        }
        int i = 1;
        bool flag = false;
        while(i < n && ar[i] == ar[i - 1]){
            i++;
        }
        if(i == n){
            return true;
        }
        else if(ar[i] > ar[i - 1]){
            flag = true;
        }
        else{
            flag = false;
        }
        
        if(flag){
            for(int i = 1 ; i < n ; i++){
                if(ar[i] < ar[i - 1]){
                    return false;
                }
            }
            return true;
        }
        for(int i = 1 ; i < n ; i++){
            if(ar[i - 1] < ar[i]){
                return false;
            }
        }
        return true;
    }
};