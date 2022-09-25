class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& ar) {
        unordered_map<int,int> mymap_row;
        unordered_map<int,int> mymap_col;
        for(int i = 0 ; i < ar.size() ; i++){
            int row = ar[i][0];
            int col = ar[i][1];
            mymap_row[row]++;
            mymap_col[col]++;
        }
        
        int ans = 0;
        int count = 0;
        
        for(int i = 0 ; i < m ; i++){
            int row = mymap_row[i];
            for(int j = 0 ; j < n ;j++){
                int col = mymap_col[j];
                int val = row + col;
                if(val % 2 != 0){
                    count++;
                }
            }
        }
        
        return count;
        
    }
};