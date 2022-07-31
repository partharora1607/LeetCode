class Solution {
public:
    vector<string> res;

void helper(int n , int openN , int closedN , string s){
    if(closedN == n && openN == n){
        res.push_back(s);
        return;
    }
    if(openN < n){
        helper(n , openN + 1 , closedN , s + '(');
    }
    if(openN> closedN){
        helper(n , openN , closedN + 1 , s + ')');      
    }

}

vector<string> generateParenthesis(int n)
{
    string s = "";
    helper(n ,  0 , 0 , s);
    return res;
}
};