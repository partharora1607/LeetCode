class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();   
        int si = 0 ,ei = n;
        vector<int> dp;
        for(int i = 0 ; i <  n ; i++){
            if(s[i] == 'I'){
                dp.push_back(si);
                si++;
            }
            else{
                dp.push_back(ei);
                ei--;
            }
        }
        dp.push_back(si);
        return dp;
    }
};