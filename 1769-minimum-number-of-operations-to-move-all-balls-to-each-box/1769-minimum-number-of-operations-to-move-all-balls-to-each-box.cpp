class Solution {
public:
    vector<int> minOperations(string s) {
        vector<int> have;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                have.push_back(i);
            }
        }
        
        vector<int> v;
        
        for(int i = 0; i < s.size() ; i++){
            int ans = 0;
            
            for(int j = 0 ; j < have.size();j++){
                ans += abs(i - have[j]);
            }
            v.push_back(ans);
        }
        
        return v;  
        
    }
};