#include <bits/stdc++.h>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> set_nums;
        for(int num : nums) {
            if(set_nums.contains(num)) {
                return true;
            }
            set_nums.insert(num);
        }
        return false;
    }
};