class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans = 0.00000;
        // for(auto i:nums2){
        //     nums1.push_back(i);
        // }
        // sort(nums1.begin(), nums1.end());
        int i=0,j=0,k=0;
        vector<int> temp(nums1.size()+nums2.size(), 0);
        while(i<nums1.size() and j<nums2.size()){
            if(nums1[i]<nums2[j]){
                temp[k++] = nums1[i++];
            }else{
                temp[k++] = nums2[j++];
            }
        }
        while(i<nums1.size()){
            temp[k++] = nums1[i++];
        }
        while(j<nums2.size()){
            temp[k++] = nums2[j++];
        }
        int n = temp.size();
        if(n%2!=0){
            ans = temp[n/2];
        }else{
            ans = (temp[n/2]+temp[n/2-1])/2.0;
        }
        return ans;
    }
};