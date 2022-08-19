class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> s1;
        stack<int> freq;
        s1.push(s[0]);
        freq.push(1);
        int n = s.length();
        for(int i= 1;i<n;i++){
            if(s1.empty()){
                s1.push(s[i]);
                freq.push(1);
            }
            else{
                if(s[i] != s1.top()){
                    s1.push(s[i]);
                    freq.push(1);
                }
                else{
                    if(freq.top() != k - 1){
                        s1.push(s[i]);
                        int currfreq = freq.top();
                        freq.push(currfreq + 1);
                    }
                    else{
                        int count = 0; 
                        while(!s1.empty() && count != k - 1){
                            s1.pop();
                            freq.pop();
                            count++;
                        }
                    }
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