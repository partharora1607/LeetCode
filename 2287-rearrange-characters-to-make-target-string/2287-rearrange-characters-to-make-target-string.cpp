class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> mymap;
        for(int i = 0; i < s.size() ; i++){
            mymap[s[i]]++;
        }
        
        int ans = INT_MAX;
        
        unordered_map<char , int> mymap2;
        
        for(int i =0 ; i < target.size(); i++){
            mymap2[target[i]]++;
        }
        
        for(int i =0 ; i < target.size() ; i++){
            ans = min(ans , mymap[target[i]] / mymap2[target[i]]);
        }
        
        return ans;
        
        
    }
};