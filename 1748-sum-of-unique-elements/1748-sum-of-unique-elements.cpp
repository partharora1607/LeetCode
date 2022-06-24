class Solution {
public:
     int sum = 0;
    int sumOfUnique(vector<int>& ar) {
        unordered_map<int,int> mymap;
        for(int i = 0 ; i < ar.size(); i++){
            mymap[ar[i]]++;
        }
        unordered_map<int,int>::iterator it = mymap.begin();
        while(it != mymap.end()){
            if(it->second == 1){
                sum += it->first;
            }
            it++;
        }
        return sum;
    }
};