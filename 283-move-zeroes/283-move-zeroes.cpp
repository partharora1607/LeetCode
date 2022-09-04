class Solution {
public:
    void moveZeroes(vector<int>& ar) {
        int n = ar.size();
        int index = 0;
        for(int i = 0 ; i < n ; i++){
            if(ar[i] != 0){
                swap(ar[index++] , ar[i]);
            }
        }
        
    }
};