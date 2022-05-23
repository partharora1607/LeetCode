class Solution {
public:
    void sortColors(vector<int> &ar)
{
    int index1 = 0;
    int index2 = ar.size() - 1;
    int i = 0;
    while (i <= index2)
    {
        if (ar[i] == 0)
        {
            swap(ar[index1++], ar[i]);
            i++;
        }
        else if (ar[i] == 2)
        {
            swap(ar[index2--], ar[i]);
        }
        else{
                    i++;

        }
    }
}
};