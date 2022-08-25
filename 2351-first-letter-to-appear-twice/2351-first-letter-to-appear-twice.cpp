class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int> mymap;
        for(int i = 0 ; i < s.length();i++){
            mymap[s[i]]++;
            if(mymap[s[i]] == 2){
                return s[i];
            }
        }
        return 'c';
    }
};