class Solution {
public:
    string reverseVowels(string s) {
        int prev = -1;
        int n = s.size();
        string s1;
        for(int i = n - 1 ; i >=0 ; i--){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                s1+= s[i];
            }
           else if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
               s1+=s[i];
           }
        }
        int index = 0;
        for(int i = 0;  i < n ; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                s[i] = s1[index++];
            }
            else if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
               s[i] = s1[index++];
           }
            
        }
        return s;
    }
};