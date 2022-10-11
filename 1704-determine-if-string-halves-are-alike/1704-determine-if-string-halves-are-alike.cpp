class Solution {
public:
    bool halvesAreAlike(string s) {
        int half = s.size() / 2;
        int c1 = 0, c2 = 0;
        for(int i = 0 ; i < half ; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                c1++;
            }
            else if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                c1++;
            }
        }
        for(int i = half ; i < s.size() ; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                c2++;
            }
            else if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                c2++;
            }
        }
        return c1 == c2;
    }
};