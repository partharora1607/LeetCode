class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> myset;
        // unordered_map<char,int> mymap;
        for(int i = 0 ; i < jewels.size();i++){
            myset.insert(jewels[i]);
        }
        int ans = 0;
        for(int i = 0 ; i < stones.size() ; i++){
            if(myset.count(stones[i]) == 1){
                ans++;
            }
        }
        return ans;
    }
};