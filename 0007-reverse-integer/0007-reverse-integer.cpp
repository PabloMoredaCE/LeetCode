class Solution {
public:
    int reverse(int x) {
        int32_t rev_num = 0;
        if(x > 0) {
            while (x > 0) {
                if(rev_num > INT_MAX / 10) { return 0; }
                rev_num = rev_num * 10 + x % 10;
                x = x / 10;
            }
        } else if (x < 0) {
            while (x < 0) {
                if(rev_num < (INT_MIN / 10)) { return 0; }
                rev_num = rev_num * 10 + x % 10;
                x = x / 10;
            }
        }
        return rev_num;
    }
};