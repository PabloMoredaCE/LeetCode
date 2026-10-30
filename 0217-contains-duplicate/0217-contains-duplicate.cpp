class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set_nums;
        for(int i = 0; i < nums.size(); ++i) {
            if(set_nums.contains(nums[i])) {
                return true;
            }
            set_nums.insert(nums[i]);
        }
        return false;
    }
};