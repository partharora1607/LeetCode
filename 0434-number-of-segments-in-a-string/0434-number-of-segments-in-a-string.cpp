class Solution {
public:
    int countSegments(string s) {
        s+= ' ';
        int ans = 0;
        for(int i =0 ; i < s.size(); i++){
            if(s[i] == ' '&& i - 1 >= 0 && s[i - 1] != ' '){
                ans ++;
            }
        }
        return ans;
    }
};