class Solution {
public:
    
    int ans = INT_MAX;
    vector<vector<int>> res;
    
    vector<vector<int>> minimumAbsDifference(vector<int>& ar) {
        int n = ar.size();
        sort(ar.begin() , ar.end());
        for(int i = 1;  i < n; i++){
            int diff = ar[i] - ar[i - 1];
            if(diff < ans){
                ans = diff;
                res.clear();
                vector<int> ok;
                ok.push_back(ar[i - 1]);
                ok.push_back(ar[i]);
                res.push_back(ok);
            }
            else if(ans == diff)
            {
                vector<int> ok;
                ok.push_back(ar[i - 1]);
                ok.push_back(ar[i]);
                res.push_back(ok);
            }
        }
        return res;
    }
};