class Solution {
public:
    bool halvesAreAlike(string s) {
        
        unordered_map<char,int> mymap;
        mymap['a']++; 
        mymap['e']++;
        mymap['i']++;
        mymap['o']++;
        mymap['u']++;
        mymap['A']++;
        mymap['E']++;
        mymap['I']++;
        mymap['O']++;
        mymap['U']++;
        
        int half = s.size() / 2;
        int c1 = 0, c2 = 0;
        for(int i = 0 ; i < half ; i++){
            if(mymap.count(s[i])){
                c1++;
            }
        }
        for(int i = half ; i < s.size() ; i++){
            if(mymap.count(s[i])){
                c2++;
            }
        }
        return c1 == c2;
    }
};