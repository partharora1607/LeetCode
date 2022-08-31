class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string ans1 = "";
        string ans2 = "";
        int n1 = word1.size();
        for(int i = 0 ; i < n1 ; i++){
            ans1 += word1[i];
        }
        int n2 = word2.size();
        for(int i = 0 ; i < n2 ; i++){
            ans2 += word2[i];
        }
        return ans1 == ans2;
    }
};