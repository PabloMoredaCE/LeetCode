class Solution {
public:

    int minMoves2(vector<int>& nums) {        
        int n = nums.size();
        //Order the middle element
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        //Median
        int median = nums[n / 2];

        int count = 0;
        for(int i = 0; i < n; ++i) {
            //For each number, we get the difference to the median
            count += abs(median - nums[i]);
        }
        return count;
    }
};