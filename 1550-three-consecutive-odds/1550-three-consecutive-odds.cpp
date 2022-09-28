class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& ar) {
        string s;
        for(int i = 0 ; i < ar.size() ; i++)
        {
            if(ar[i] % 2 != 0){
                s += 'o';
            }
            else{
                s +='e';
            }
        }
        return s.find("ooo") >= 0 &&  s.find("ooo") <= ar.size() - 1;
    }
};