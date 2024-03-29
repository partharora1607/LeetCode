class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        bool first = false;
        if(word[0] >= 'A' && word[0] <= 'Z'){
            first = true;
        }
        for(int i = 0 ; i < word.size() ; i++){
            if(word[i] >= 'A' && word[i] <= 'Z'){
                count++;
            }
        }
        return count == 0 || count == word.size() || count == 1 && first;
    }
};