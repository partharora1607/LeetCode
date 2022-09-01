class Solution {
public:
    // #define H 10001
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> rightside(n);
        vector<int> leftside(n);
        bool yes = false;
        for(int i = n -1 ; i >=0 ;i--){
            if(s[i]==c){
                rightside[i] = 0;
                yes = true;
            }
            else{
                if(yes){
                    rightside[i] = rightside[i + 1] + 1;
                }
                else{
                    rightside[i] = INT_MAX;
                }
            }
        }
        yes = false;
        for(int i = 0  ;i < n ;i++){
            if(s[i] == c){
                leftside[i] = 0;
                yes = true;
            }
            else{
                if(yes){
                    leftside[i] = leftside[i -1] + 1;
                }
                else{
                    leftside[i] = INT_MAX;
                }
            }
        }
        vector<int> res(n);
        for(int i = 0 ;  i  < n  ; i ++){
            res[i] = min(leftside[i],rightside[i]);
        }
        return res;
    }
};