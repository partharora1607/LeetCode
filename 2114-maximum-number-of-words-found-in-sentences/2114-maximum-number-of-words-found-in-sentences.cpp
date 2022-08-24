class Solution {
public:
    int mostWordsFound(vector<string>& v) {
        int ans = 0;
        int n = v.size();
        for(int i = 0 ; i < n ;i ++){
            string s = v[i];
            int count_spaces = 0;
            for(int j = 0 ; j < s.size();j++){
                if(s[j] == ' ')
                {
                    count_spaces++;
                }
            }
            ans = max(ans , count_spaces + 1);
        }
        return ans;
    }
};