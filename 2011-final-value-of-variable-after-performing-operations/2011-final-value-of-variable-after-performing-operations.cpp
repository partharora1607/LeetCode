class Solution {
public:
    int finalValueAfterOperations(vector<string>& v) {
        int n = v.size();
        int ans =0 ;
        for(int i = 0 ; i < n ;i++){
            if(v[i][1] == '-'){
                ans--;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};