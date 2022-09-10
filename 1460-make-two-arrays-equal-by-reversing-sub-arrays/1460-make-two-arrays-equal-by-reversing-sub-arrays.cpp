class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& ar) {
        int n = ar.size();
        unordered_map<int,int> mymap;
        for(int i = 0 ; i <  n ; i ++){
            mymap[ar[i]]++;
        }
        for(int i = 0 ; i  < target.size(); i++){
            mymap[target[i]]--;
        }
        auto it = mymap.begin();
        while(it != mymap.end()){
            if(it->second != 0){
                return false;
            }
            it++;
        }
        return true;
    }
};