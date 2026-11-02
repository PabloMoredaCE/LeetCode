class Solution {
public:
    int minMoves(vector<int>& nums) {      
        int n = nums.size();
        //Get the minimum element
        int min = *min_element(nums.begin(), nums.end());

        int count = 0;
        //O(N)
        for(int i = 0; i < n; ++i) {
            //Count for the values of all elements
            count += nums[i];
        }
        //The total - the value of all elements if they were the minimum element
        return count - (n * min);
    }
};