class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& v) {
        vector<int> res;
        int m = v.size();
        int n =v[0].size();
        vector<int> row;
        for(int i = 0 ; i < m ; i ++){
            int ans = INT_MAX;
            for(int j = 0 ; j  < n ; j++){
                ans = min(ans , v[i][j]);
            }
            row.push_back(ans);
        }
        vector<int> col;
        for(int j = 0;  j < n ; j ++)
        {
            int ans  = INT_MIN;
            for(int i = 0 ; i < m ; i ++){
                ans = max(ans , v[i][j]);
            }    
            col.push_back(ans);
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ;j++){
                if(v[i][j] == row[i] && v[i][j]  == col[j]){
                    res.push_back(v[i][j]);
                }
            }
        }
        return res;
    }
};