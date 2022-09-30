class Solution {
public:
    bool validMountainArray(vector<int>& ar) {
        if(ar.size() < 3){
            return false;
        }
        if(ar[0] > ar[1])
        {
            return false;
        }
        int n = ar.size();
        if(ar[n - 1] > ar[n - 2]){
            return false;
        }
        bool point_found = false;
        for(int i = 1 ; i < n ; i++){
            if(ar[i] == ar[i - 1]){
                return false;
            }
            else if(point_found){
                if(ar[i] > ar[i - 1]){
                    return false;
                }
            }
            else{
                if(ar[i] < ar[i - 1]){
                    point_found = true;
                }
            }
        }
        return true;
    }
};