class Solution {
public:
    bool checkIfExist(vector<int>& ar) {
        unordered_map<int,int> mymap;
        for(int i = 0 ; i < ar.size() ;i++){
            if(mymap.count(ar[i] * 2)){
                return true;
            }
            else if(ar[i] % 2 == 0 && mymap.count(ar[i] / 2))
            {
                return true;
            }
            mymap[ar[i]]++;
        }
        return false;
    }
};