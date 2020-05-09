class Solution {
public:
/*
    int mySqrt(int x) {
        if (x <= 1) return x;
        size_t tmp = 1;
        while (tmp * tmp <= x) ++tmp;
        return tmp - 1;
    }
*/
    int mySqrt(int x) {
        if (x <= 1) return x;

        size_t left = 1, right = x;
        while (1) {
            size_t tmp = (left + right) / 2;
            if (tmp * tmp > x) {
                right = tmp - 1;
            } else if (tmp * tmp < x) {
                if ((tmp+1) * (tmp+1) > x) return tmp;
                left = tmp + 1;
            } else {
                return tmp;
            }
        }
    }
};
