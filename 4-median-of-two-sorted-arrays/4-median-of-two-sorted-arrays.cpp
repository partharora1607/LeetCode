class Solution {
public:
    double findMedianSortedArrays(vector<int> &ar1, vector<int> &ar2)
{
    int n = ar1.size();
    int m = ar2.size();
    int size = n + m;
    int half = size / 2;
    if (n == 0)
    {
        return m % 2 == 0 ? (double)(ar2[(m - 1) / 2] + ar2[(m - 1) / 2 + 1]) / 2 : (double)(ar2[(m - 1) / 2]);
    }
    if (m == 0)
    {
        return n % 2 == 0 ? (double)(ar1[(n - 1) / 2] + ar1[(n - 1) / 2 + 1]) / 2 : (double)(ar1[(n - 1) / 2]);
    }
    if (m > n)
    {
        return findMedianSortedArrays(ar2, ar1);
    }
    int left2 = 0, right2 = m - 1;
    int r1, mid;
    int leftvalue1, leftvalue2, rightvalue1, rightvalue2;
    while (left2 <= right2)
    {
        mid = (left2 + right2) / 2;
        r1 = half - mid - 2;

        leftvalue1 = INT_MIN;
        rightvalue1 = INT_MAX;
        leftvalue2 = INT_MIN;
        rightvalue2 = INT_MAX;

        if (mid >= 0)
        {
            leftvalue2 = ar2[mid];
        }
        if (mid + 1 < ar2.size())
        {
            rightvalue2 = ar2[mid + 1];
        }
        if (r1 >= 0)
        {
            leftvalue1 = ar1[r1];
        }
        if (r1 + 1 < ar1.size())
        {
            rightvalue1 = ar1[r1 + 1];
        }
        if (leftvalue2 <= rightvalue1 && leftvalue1 <= rightvalue2)
        {
            if (size % 2 == 0)
            {
                return (max(leftvalue1, leftvalue2) + min(rightvalue1, rightvalue2)) / 2.0;
            }
            else
            {
                return min(rightvalue1, rightvalue2);
            }
        }
        else if (leftvalue1 > rightvalue2)
        {
            left2 = mid + 1;
        }
        else
        {
            right2 = mid - 1;
        }
    }
    if (right2 < 0)
    {
        r1 = half - 1;
        if (r1 >= 0)
        {
            leftvalue1 = ar1[r1];
        }
        rightvalue1 = INT_MAX;
        if (r1 + 1 < ar1.size())
        {
            rightvalue1 = ar1[r1 + 1];
        }
        leftvalue2 = INT_MIN;
        rightvalue2 = ar2[0];
        if (size % 2 == 0)
        {
            return (double)((leftvalue1 + min(rightvalue1, rightvalue2))) / 2.0;
        }
        else
        {
            return min(rightvalue1, rightvalue2);
        }
    }
    return 0.0;
}
};