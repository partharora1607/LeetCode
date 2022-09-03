class Solution {
public:
    int countWords(vector<string>& v1, vector<string>& v2) {
        unordered_map<string,int> mymap;
        for(int i = 0; i < v1.size() ;i++){
            mymap[v1[i]]++;
        }
        int ans = 0;
        unordered_map<string,int> mymap2;
        for(int i = 0 ; i < v2.size() ;i++){
            mymap2[v2[i]]++;
        }
        for(int i = 0 ; i < v1.size() ;i++){
            if(mymap[v1[i]] == 1 && mymap2[v1[i]] == 1){
                ans++;
            }
        }
        return ans;
    }
};