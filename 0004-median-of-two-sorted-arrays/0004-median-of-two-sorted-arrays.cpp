class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int n1, n2 = 0;
        //Pointers
        int i, k = 0;
        for(int j = 0; j <= (n + m) / 2; ++j) {
            n2 = n1;
            if(i != m && k != n) {
                if(nums1[i] < nums2[k]) {
                    n1 = nums1[i++];
                } else {
                    n1 = nums2[k++];
                } 
            } else if(i < m) {
                    n1 = nums1[i++];
                } else {
                    n1 = nums2[k++];
                }
            }    

        //Odd
        if((m + n) % 2 != 0) {
            return static_cast<double>(n1);
        } else {
            //Even
            return (static_cast<double>(n1) + static_cast<double>(n2)) / 2.0;
        }  
    }
};
