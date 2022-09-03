class Solution
{
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (abs(arr[i] - arr[j]) <= a)
                {
                    for (int k = j + 1; k < arr.size(); k++)
                    {
                        int B = abs(arr[j] - arr[k]);
                        int C = abs(arr[k] - arr[i]);
                        if (B <= b and C <= c)
                        {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};

// 3,0,1,1,9,7
// 0 1 1 3 7 9
// 7 ,2 ,3

// 0 - > 1 , 1, 3 , 7
// 1 - > 0 ,1 , 3 , 7
// 3 - > 0, 1 , 1 , 9
// 7 - > 0 , 1 1 3 7 9 
// 9 -> 

// x - x + min(a,b,c);
// x = > x + 2;
// 0 ->   0 - 2
// 1 ->   0 - 3
// 1 ->   0 - 3
// 3 ->   1 - 5
// 9 ->   7 - 11