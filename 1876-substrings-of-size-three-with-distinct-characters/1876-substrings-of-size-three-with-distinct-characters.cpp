class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size() < 3){
            return 0;
        }
        
        unordered_map<char,int> mymap;
        
        for(int i =0 ; i < 3 ;i++){
            mymap[s[i]]++;
        }
        
        int ans = 0;
        if(mymap.size() == 3){
            ans++;
        }
        
        int k = 0;
        
        for(int i = 3 ; i < s.size(); i++,k++){
            mymap[s[k]]--;
            if(mymap[s[k]] <= 0){
                mymap.erase(s[k]);
            }
            mymap[s[i]]++;
            if(mymap.size() == 3){
                ans++;
            }
        }
        
        auto it = mymap.begin();
        while(it != mymap.end()){
            cout << it->first << endl;
            it++;
        }
        
       return ans;
        
        
    }
};