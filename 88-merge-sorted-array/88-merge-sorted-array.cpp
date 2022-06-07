class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0) {
            nums1=nums2;
            return;
        }
        else if(n==0) return;
        int i=m-1, j = n-1, k = m+n-1;
        while(i>=0 and j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }
            else if(nums1[i]<=nums2[j]){
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        while(j>=0){
            nums1[k] = nums2[j];j--;k--;
        }
    }
};