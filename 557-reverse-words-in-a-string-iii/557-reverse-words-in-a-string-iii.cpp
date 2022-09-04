class Solution {
public:
    
    
    string reverseWords(string s) {
        s+= ' ';
        int si = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == ' '){
                int ii = si , jj = i - 1;
                while(ii < jj){
                    swap(s[ii] , s[jj]);
                    ii++;
                    jj--;
                }
                si = i + 1;
            }
        }
        s.pop_back();
        return s;
    }
};