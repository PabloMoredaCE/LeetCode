class Solution {
public:
    int climbStairs(int n) {
        int current = 1;
        int previous = 1;
        for(int i = 1; i < n; ++i) {
            int next = current + previous;
            previous = current;
            current = next;
        }
        return current;
    }
};