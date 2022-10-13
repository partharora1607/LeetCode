class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        bool good = true;
        
        unordered_map<char , int> mymap;
        for(int i= 0 ; i < chars.size(); i++){
            mymap[chars[i]]++;
        }
        
        for(int i =0 ; i < words.size(); i++){
            unordered_map<char , int> temp;
            temp = mymap;
            string s = words[i];
            good = true;
            for(int i =0;i < s.size();i++){
                if(temp.count(s[i]) == 0){
                    good = false;
                    break;
                }
                temp[s[i]]--;
                if(temp[s[i]] == 0){
                        temp.erase(s[i]);
                }
            }
            if(good){
                ans += s.size();
            }
        }
        return ans;
    }
};