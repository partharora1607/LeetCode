class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i = 0  , j = 0;
        string ans;
        while(i  < word1.size() && j < word2.size()){
            if(word1[i] > word2[j]){
                ans += word1[i];
                i++;
            }
            else if(word1[i] == word2[j]){
                string s1 = word1.substr(i+1);
                string s2 = word2.substr(j+1);
                if(s1 > s2){
                    ans += word1[i];
                    i++;
                }
                else{
                    ans += word2[j];
                    j++;
                }
            }
            else{
                ans += word2[j];
                j++;
            }
        }
        while(i < word1.size()) ans += word1[i++];
        while(j < word2.size()) ans += word2[j++];
        return ans;
    }
};