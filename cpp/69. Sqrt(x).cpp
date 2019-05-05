class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1)
            return x;
        int left = 1, right = x / 2;
        int lastLeft;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (x / mid < mid) // x < mid*mid
                right = mid-1;
            else if (x / mid > mid)
            {
                left = mid+1;
                lastLeft = mid;
            }
            else
                return mid;
        }
        return lastLeft;
    }
};