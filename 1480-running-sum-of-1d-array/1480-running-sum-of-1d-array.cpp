class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        result.resize(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j <= i; j++) {
                result[i] += nums[j];
            }
        } 
        return result;  
    }
};