class Solution {
public:
    
    vector<vector<int>> res;
    
    void helper(vector<int> &ar , vector<int> &output , int si , int ei){
        if(si > ei){
            res.push_back(output);
            return;
        }
        
        helper(ar , output , si + 1 , ei);
        output.push_back(ar[si]);
        helper(ar , output , si + 1 , ei);
        output.pop_back();        
    }
    
    
    vector<vector<int>> get_all_subsets(vector<int>& ar){
        vector<int> output;
        helper(ar,output , 0 , ar.size() - 1);
        return res;
    }
    
    int subsetXORSum(vector<int>& ar) {
        vector<vector<int>> output = get_all_subsets(ar);
        int ans  = 0;
        for(int i = 0 ; i < output.size() ; i++){
            int Xor = 0;
            for(int j = 0 ; j < output[i].size() ; j++){
                Xor = Xor ^ output[i][j];
            }
            ans += Xor;
        }
        return ans;
    }
};