class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& ar) 
    {
        vector<vector<int>> dp(m , vector<int>(n , 0));
        unordered_map<int,int>mymap_row;
        unordered_map<int,int>mymap_col;
        for(int i =0 ;i < ar.size();i++){
            int row = ar[i][0];
            int col = ar[i][1];
            mymap_row[row]++;
            mymap_col[col]++;
        }
        for(int i = 0 ; i < m ; i++){
            int val = mymap_row[i];
            for(int j = 0 ; j < n;j++){
                dp[i][j] += val;
            }
        }
        
        
        
        for(int j = 0 ; j < n ;j++){
            int val = mymap_col[j];
            cout << "val" << " " << val << endl;
            for(int i = 0 ; i < m ; i++){
                dp[i][j] += val;
            }
        }
        
        int count = 0;
        
        for(int i = 0 ; i < m ;i++){
            for(int j =0; j < n ;j++){
                if(dp[i][j] % 2 != 0){
                    count++;
                }
            }
        }
        return count;
        
//         int count = 0;
//         int val1 , val2;
//         for(int i = 0 ; i < m ;i++){
//             val1 = mymap_row[i];
//             int j;
//             for(j =0 ; j < n; j++){
//                 val2 = mymap_col[j];
//             dp[i][j] = val1 + val2;
//              if(dp[i][j] % 2 != 0)  
//                 {
//                     count++;
//               }
//             }
//         }
//         return count;
                
    }
};