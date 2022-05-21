class Solution {
public:
int maxSubArray(vector<int>& array) 
    {
        if(array.size() == 1)
            return array[0];
        
        int maxSoFar = -10000; // Better to use INT_MIN
        int currMax = -10000;
        
        for(int i = 0; i < array.size(); i++)
        {
            currMax = max(array[i], currMax + array[i]) ;
            maxSoFar = max(maxSoFar, currMax);
        }
        
        return maxSoFar;
    }

};