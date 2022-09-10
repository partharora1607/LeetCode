class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& ar) {
       vector<int> freq(10001, 0);
        for(int i = 0 ; i < target.size() ; i ++){
            freq[target[i]]++;
        }
        for(int i = 0 ; i  < ar.size() ; i++){
            freq[ar[i]]--;
        }
        for(int i = 0 ; i < 1001; i++){
            if(freq[i] != 0){
                return false;
            }
        }
        return true;
    }
};