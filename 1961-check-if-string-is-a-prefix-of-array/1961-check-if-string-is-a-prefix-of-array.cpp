class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string res;
        for(int i = 0 ; i < words.size() && s.size() > res.size(); i++){
            res += words[i];
        }
        return res == s;
    }
};