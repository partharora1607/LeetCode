class Solution {
public:
    int countPoints(string s) {
        vector<int> red(10,0);
        vector<int> green(10,0);
        vector<int> blue(10,0);
        int n = s.size();
        
        int ans = 0;
        
        for(int i = 0 ; i < n ; i+=2){
            char ch = s[i + 0];
            int val = s[i + 1] - '0';
            if(ch == 'B'){
                blue[val] = 1;
            }
            else if(ch == 'G'){
                green[val] = 1;
            }
            else{
                red[val] = 1;
            }
        }
        for(int i = 0 ; i < 10 ; i++){
            if(blue[i] == 1 && green[i] == 1 && red[i] == 1){
                ans += 1;
            }
        }
        return ans;
        
    }
};