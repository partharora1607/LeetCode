class Solution {
public:
    int maxNumberOfBalloons(string s) {
        unordered_map<char,int> mymap;
        for(int i = 0 ; i < s.size() ; i++){
            mymap[s[i]]++;
        }
        return min({mymap['b'] , mymap['a'], mymap['l'] / 2 , mymap['o'] / 2 , mymap['n']});
    }
};