class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<string,int> mymap;
        vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};       
        int ans = 0;
        for(int i = 0 ; i < words.size(); i++)
        {
            string s1;
            for(int j = 0 ;j <words[i].size();j++){
                s1 += v[words[i][j] - 'a']; 
            }
            if(mymap.count(s1) == 0){
                mymap[s1]++;
                ans++;
            }       
        }        
        return ans;
    }
};