class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
        {
            return 1.0 / power(x, -(long long)n);
        }
        else
            return power(x, n);
    }
    
    double power(double x, unsigned int n)
    {
        if (n == 0)
            return 1.0;
        double half = power(x, n / 2);
        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }
};