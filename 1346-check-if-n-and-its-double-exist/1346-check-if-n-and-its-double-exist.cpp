class Solution {
public:
    bool checkIfExist(vector<int>& ar) 
    {
        sort(ar.begin(), ar.end() , greater<int>());
        unordered_map<int,int> mymap;
        int n = ar.size();
        for(int i = 0 ; i < n ;i++){
            if(ar[i] > 0)
            {
                if(mymap.count(2 * ar[i]))
                {
                    return true;
                }
            }
            else
            {
                if(ar[i] % 2 == 0 && mymap.count(ar[i] / 2)){
                    return true;
                }
            }
            mymap[ar[i]]++;
        }
        for(int i = 0 ; i  < ar.size() ; i++){
            cout << ar[i] << " ";
        }
        return false;
    }
};