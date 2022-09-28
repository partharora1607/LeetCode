class Solution {
public:
    bool uniqueOccurrences(vector<int>& ar) {
        unordered_map<int,int> mymap;
        for(int i = 0 ; i < ar.size() ; i++)
        {
            mymap[ar[i]]++;       
        }
        unordered_map<int,int> ok;
        auto it = mymap.begin();
        while(it != mymap.end()){
            if(ok.count(it->second) == 1){
                return false;
            }
            ok[it->second]++;
            it++;
        }
        return true;
    }
};