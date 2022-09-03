class Solution {
public:
    string truncateSentence(string s, int k) {
        int count = 0;
        s+=' ';
        int n = s.length();
        int i =0 ;
        for(; i <= n && count < k ; i++){
            if(s[i] == ' ')
            {
                count++;
                if(count == k)
                {
                    break;
                }
            }
        }
        return s.substr(0 ,i);
    }
    
};