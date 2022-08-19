class Solution {
public:
    string removeDuplicates(string s) {
        if(s.length() <= 1){
            return s;
        }
        stack<char>s1;
        s1.push(s[0]);
        int n = s.length();
        
        for(int i = 1 ; i < n ;i++){
            if(s1.empty()){
                s1.push(s[i]);
            }
            else{
                if(s[i] == s1.top()){
                    s1.pop();
                }
                else{
                    s1.push(s[i]);
                }
            }
        }
        string ans;
        while(!s1.empty()){
            ans += s1.top();
            s1.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
            
        
    }
};