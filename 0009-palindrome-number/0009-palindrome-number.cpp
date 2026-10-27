class Solution {
public:

    bool willMultiplicationOverflow(unsigned int a, unsigned int b) {
        if (a == 0 || b == 0) {
            return false; // Multiplication with zero never overflows
        }
        return a > numeric_limits<unsigned int>::max() / b;
    }

    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int origin = x;
        int rev_num = 0;
        while (x > 0) {
            rev_num = rev_num * 10 + x % 10;
            x = x / 10;
            if(willMultiplicationOverflow(rev_num, 10)) {
                break;
            }
        }
        return rev_num == origin;
    }
};

