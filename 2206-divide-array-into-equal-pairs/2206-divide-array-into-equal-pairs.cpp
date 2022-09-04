class Solution {
public:
    bool divideArray(vector<int>& ar) {
          int n = ar.size();
        unordered_map<int,int> mymap;
        for(int i = 0 ; i  < n ; i++){
            mymap[ar[i]]++;
            if(mymap[ar[i]] % 2 == 0){
                mymap.erase(ar[i]);
            }
        }
        return mymap.size() == 0;
    }
};