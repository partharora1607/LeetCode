class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int j = 0;
        int i = 0;
        while (j < name.size() && i < typed.size())
        {
            if (name[j] == typed[i])
            {
                j++;
                i++;
            }
            else if (j - 1 >= 0 && name[j - 1] == typed[i])
            {
                i++;
            }
            else
            {
                return false;
            }
        }
        int lastindex = name.size() - 1;
        while(i < typed.size() && typed[i] == name[lastindex]){
            i++;
        }
        return i == typed.size() && j == name.size();
    }
};