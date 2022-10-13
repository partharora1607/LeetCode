class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char , int> mymap;
        for(int i = 0 ; i < brokenLetters.size() ; i++){
            mymap[brokenLetters[i]]++;
        }
        
        text += ' ';
        string s;
        int count = 0;
        
        bool flag = false;
        
        for(int i = 0 ; i < text.size() ; i++){
            if(text[i] != ' '){
                if(mymap.count(text[i])){
                    flag = true;
                }
            }
            else{
                if(flag == false){
                    count++;
                }
                flag = false;
            }
        }
        
        return count;
        
    }
};