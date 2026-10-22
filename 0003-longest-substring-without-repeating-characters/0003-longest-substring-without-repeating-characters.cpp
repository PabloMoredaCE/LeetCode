class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int count = 0;
        unordered_set<char> set;
        int left = 0;
        for(int right = 0; right < n; ++right) {
            if(set.count(s[right]) == 0) {
                set.insert(s[right]);
                count = max(count, right - left + 1);
            } else {
                while(set.count(s[right])) {
                    set.erase(s[left]);
                    left++;
                }
                set.insert(s[right]);
            }
        }
        return count;
    }
};