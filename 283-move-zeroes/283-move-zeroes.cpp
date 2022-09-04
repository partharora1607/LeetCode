class Solution {
public:
    void moveZeroes(vector<int>& ar) {
        int n = ar.size();
        int index = 0;
        for(int i = 0 ; i < n ;i++){
            if(ar[i] != 0){
                ar[index++] = ar[i];
            }
        }
        for(int i = index ; i < n ;i++){
            ar[i] = 0;
        }
    }
};