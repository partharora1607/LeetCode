class Solution {
public:
    string makeGood(string s) {
        if(s.length() <= 1){
            return s;
        }
        
        stack<char> s1;
        int n = s.length();
        s1.push(s[n-1]);

        
        for(int i = n - 2 ; i >= 0 ; i--){
            if(s1.empty()){
                s1.push(s[i]);
            }   
            else{
                int val = abs(s[i] - s1.top());
                if(val == 32){
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
        return ans;
        
        
    }
};