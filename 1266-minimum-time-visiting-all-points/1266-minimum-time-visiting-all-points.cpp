class Solution {
public:
    
    int helper(int si , int ei , int x1 , int y1){
        if(si == x1 && ei == y1){
            return 0;
        }   
        if(y1 > ei && x1 > si){
            return helper(si + 1 , ei + 1 , x1 , y1) + 1;
        }
        if(y1 > ei && x1 < si){
            return helper(si - 1 , ei + 1 , x1 , y1) + 1;
        }
        
        if(x1 > si && y1 < ei){
            return helper(si + 1 , ei - 1 , x1 , y1) + 1;
        }
        if(x1 < si && y1 < ei){
            return helper(si - 1 , ei - 1 , x1 , y1) + 1;
        }
        
        if(y1 == ei && x1 > si){
            return helper(si + 1 , ei , x1 , y1) + 1;

        }
        if(y1 == ei && x1 < si){
            return helper(si - 1 , ei , x1 , y1) + 1;
            
        }
        
        if(x1 == si && y1 > ei){
            return helper(si , ei + 1 , x1 , y1) + 1;
                
        }
        if(x1 == si && y1 < ei){
            return helper(si , ei - 1 , x1 , y1) + 1;
        }
        
        return 0;
        
    }
    
    int minTimeToVisitAllPoints(vector<vector<int>>& ar) 
    {
        int ans = 0; 
        for(int i = 1; i< ar.size();i++)
        {
            int smallans = helper(ar[i - 1][0] , ar[i - 1][1] , ar[i][0] , ar[i][1]);
            ans+=smallans;
        }
        return ans;
    }
};