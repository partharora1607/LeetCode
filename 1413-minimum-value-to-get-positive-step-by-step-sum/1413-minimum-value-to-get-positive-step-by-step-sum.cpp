class Solution {
public:
    int minStartValue(vector<int>& ar) {
        int val = 1;
        int sum = 0;
        for(int i = 0 ; i < ar.size() ; i++){
            sum += ar[i];
            if(sum > 0){
                continue;
            }
            else{
                val = max(val , abs(sum) + 1);
            }
        }
        return val;
    }
};