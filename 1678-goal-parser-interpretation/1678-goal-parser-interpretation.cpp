class Solution {
public:
    string interpret(string command) {
        string ans;
        bool found = false;
        for(int i = 0 ; i < command.size(); i++){
            if(command[i] == 'G'){
                ans += 'G';
            }
            else if(command[i] == '('){
                found = true;
            }
            else if(command[i] == ')'){
                if(found){
                    if(command[i-1] == '('){
                        ans += 'o';
                    }
                    else{
                        ans += "al";
                    }
                }
                found = !found;
            }
        }
        return ans;
    }
};