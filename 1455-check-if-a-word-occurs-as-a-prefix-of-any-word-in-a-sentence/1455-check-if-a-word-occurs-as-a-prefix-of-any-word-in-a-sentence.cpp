class Solution {
public:
    int isPrefixOfWord(string s, string searchWord) {
        s += ' ';
        string str;
        int prev = 0;
        int c = 1;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == ' '){
                string save = s.substr(prev ,i-prev);
                if(save.size() >= searchWord.size()){
                    if(save.substr(0 , searchWord.size()) == searchWord){
                        return c;
                    }
                } 
                c++;
                prev = i + 1;
            }
        }
        return -1;
    }
};