class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> vec;
        set<int> s1(nums1.begin(), nums1.end());        
        set<int> s2(nums2.begin(), nums2.end());
        nums1 = vector<int> (s1.begin(), s1.end());
        nums2 = vector<int> (s2.begin(), s2.end());
        vector<int> v1;
        vector<int> v2;
        for(int i=0;i<nums1.size();i++){
            int c = count(nums2.begin(), nums2.end(), nums1[i]);
            if(c==0){
                v1.push_back(nums1[i]);
            }
        }
        for(int i=0;i<nums2.size();i++){
            int c = count(nums1.begin(), nums1.end(), nums2[i]);
            if(c==0){
                v2.push_back(nums2[i]);
            }
        }
        vec.push_back(v1);        
        vec.push_back(v2);
        return vec;

    }
};