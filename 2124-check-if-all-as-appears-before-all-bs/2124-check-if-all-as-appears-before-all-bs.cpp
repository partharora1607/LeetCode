class Solution {
public:
    bool checkString(string s) {
        int prev = s[0];
        for(int i = 1 ; i < s.size() ; i++){
            if(s[i] < prev){
                return false;
            }
            prev = s[i];
        }
        return true;
    }
};