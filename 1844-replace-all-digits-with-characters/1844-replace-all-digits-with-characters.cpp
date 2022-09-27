class Solution {
public:
    string replaceDigits(string s) {
        for(int i = 1 ; i < s.size() ; i+=2){
            int prev = s[i - 1];
            int d = s[i] - '0';
            char c = (char)(prev + d);
            s[i] = c;
        }
        return s;
    }
};