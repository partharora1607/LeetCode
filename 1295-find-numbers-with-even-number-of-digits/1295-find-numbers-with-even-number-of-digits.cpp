class Solution {
public:
    int findNumbers(vector<int>& ar) {
        int n = ar.size();
        int count = 0;
        for(int i = 0; i  < n ;  i++){
            int val = ar[i];
            if((val > 9 && val < 100) || (val > 999 && val < 10000) || (val == 100000)){
                count++;
            }
        }
        return count;
    }
};