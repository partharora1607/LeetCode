class Solution {
public:
    
    bool issubstring(string s1 , string s2){
        if(s1.size() > s2.size()){
            return false;
        }
        
        if(s1[0] == s2[0]){
            int size = s1.size();
            if(s2.substr(0 , size) == s1){
                return true;
            }
        }
        return issubstring(s1 , s2.substr(1));        
    }
    
    int numOfStrings(vector<string>& v, string s) {
        int ans = 0 ;
        for(int i = 0 ; i < v.size() ; i++){
            if(v[i].size() > s.size()){
                continue;
            }
            else
            {
                if(issubstring(v[i] , s)){
                    ans++;
                }
            }
        }

        return ans;
    }
};