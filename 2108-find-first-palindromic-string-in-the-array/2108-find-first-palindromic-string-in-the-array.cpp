class Solution {
public:
    string firstPalindrome(vector<string>& v) {
         for(int i = 0 ; i < v.size() ; i++){
             string s = v[i];
             int si = 0 , ei = s.size() - 1;
             while(si < ei){
                 if(s[si] == s[ei]){
                     si++;
                     ei--;
                 }
                 else{
                     break;
                 }
             }
             if(si >= ei){
                 return s;
             }
         }
        return "";
    }
};