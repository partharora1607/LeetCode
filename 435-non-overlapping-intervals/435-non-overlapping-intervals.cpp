class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &v)
{
    int n = v.size();
    if(n == 1){
        return 0;
    }    
    sort(v.begin() , v.end());
    int psi = v[0][0];
    int pei = v[0][1];

    int count = 0;

    for (int i = 1; i < n; i++)
    {   
        int si = v[i][0];
        int ei = v[i][1];
        if(pei > si){
            pei = min(pei ,ei);
            count++;
        }
        else{
            psi = si;
            pei = ei;
        }
    }

    return count;

}
};