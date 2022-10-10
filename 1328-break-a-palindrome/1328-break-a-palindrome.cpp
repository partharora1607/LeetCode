class Solution {
public:
    string breakPalindrome(string s) 
    {
        int n = s.size();
        if(n == 1){
            return "";
        }
        int i = 0 , j = n - 1;
        while(i < j)
        {
            int val = s[i] - 'a';
            for(int k = 0 ; k < val ; k++)
            {
                char ch = k + 'a';
                if(s[i] != ch)
                {
                    s[i] = ch;
                    return s;
                }    
            }
            i++;
            j--;
        }
        if(s[0] == 'a'){
            s[n - 1] = 'b'; 
            return s;
        }
        return ""; 
    }
};