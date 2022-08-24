class Solution {
public:
    string decodeMessage(string key, string message) {
        int n1 = key.size();
        unordered_map<char , char> mymap;
        int count = 0;
        for(int i = 0 ; i < n1; i ++)
        {
            if(key[i] == ' ' || mymap.count(key[i]) == 1){
                continue;
            }
            else{
                mymap[key[i]] = count + 'a';
                count++;
            }
        }
        int n2 = message.size();
        for(int i = 0 ; i < n2 ; i++){
            if(mymap.count(message[i]) == 1){
                message[i] = mymap[message[i]];
            }
        }
        return message;
    }
};