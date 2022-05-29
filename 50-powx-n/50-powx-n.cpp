class Solution {
public:
double myPow(double x, int n)
{
    if (x == 1)
    {
        return 1;
    }
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 1.0 / (pow(x, abs(n) - 1) * x);
    }
    return pow(x, n - 1) * x;
}
};