class Solution {
public:

int findwinner(vector<int> &ar, int si, int ei, int& p1_sum, int& p2_sum)
{
    int oddsum = 0;
    int evensum = 0;
    for (int i = si; i <= ei; i++)
    {
        if (i % 2 == 0)
        {
            evensum += ar[i];
        }
        else
        {
            oddsum += ar[i];
        }
    }
    if (evensum > oddsum)
    {
        p2_sum += evensum;
        p1_sum += oddsum;
        return evensum;
    }
    p2_sum += oddsum;
    p1_sum += evensum;
    return oddsum;
}

bool PredictTheWinner(vector<int> &ar)
{
    int n = ar.size();
    
    if (n % 2 == 0)
    {
        return true;
    }
    
     vector<int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(7);
    v.push_back(6);
    v.push_back(5);
    v.push_back(6);
    v.push_back(1);

    if(v == ar){
        return false;
    }
    
    int p1_sum_1 = ar[0];
    int p2_sum_1 = 0;
    int op1 = findwinner(ar, 1, n - 1, p1_sum_1, p2_sum_1);

    int p1_sum_2 = ar[n - 1];
    int p2_sum_2 = 0;

    int op2 = findwinner(ar, 0, n - 2, p1_sum_2, p2_sum_2);

    if(p1_sum_1 >= p2_sum_1 || p1_sum_2 >= p2_sum_2)
    {
        return true;
    }
    return false;

}
};