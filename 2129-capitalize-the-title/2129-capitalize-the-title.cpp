class Solution {
public:
    string capitalizeTitle(string s) {
        s += ' ';        
        int n = s.size();
        for(int i = 0 ; i < s.size() ; i++){
            bool flag = false;
            if(i + 1 < n && s[i + 1] == ' '){
                flag = true;
            }
            if(i + 2 < n && s[i + 2] == ' '){
                flag = true;
            }
            if(flag){
                 while(s[i] != ' '){
                     if(s[i] >= 'A' && s[i] <= 'Z'){
                         s[i] += 32;
                     }
                     i++;
                 }
            }
            else{
                if(s[i] >= 'a' && s[i] <= 'z'){
                    s[i] -= 32;   
                }
                i++;
                while(s[i] != ' '){
                    if(s[i]>= 'A' && s[i] <= 'Z'){
                        s[i] += 32;
                    }
                    i++;
                }
            }
        }
        s.pop_back();
        return s;
    }
};