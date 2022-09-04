class Solution {
public:
    string reverseOnlyLetters(string s) {
        string ok;
        int n  = s.size();
        for(int i = n - 1 ; i >= 0 ; i--){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'){
                ok+=s[i];
            }
        }
        int j = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = ok[j++];
            }
        }
        return s;
    }
};