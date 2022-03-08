class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        sort(nums1.begin(), nums1.end());        
        sort(nums2.begin(), nums2.end());
        sort(nums3.begin(), nums3.end());
        map<int, int> map;
        map[nums1[0]]++;
        for(int i=1;i<nums1.size();i++){
            if(nums1[i]!=nums1[i-1]){map[nums1[i]]++;}
        }
        map[nums2[0]]++;
        for(int i=1;i<nums2.size();i++){
            if(nums2[i]!=nums2[i-1]){map[nums2[i]]++;}
        }
        map[nums3[0]]++;
        for(int i=1;i<nums3.size();i++){
            if(nums3[i]!=nums3[i-1]){map[nums3[i]]++;}
        }
        vector<int> v;
        for(int i=0;i<map.size();i++){
            if(map[i]>1){v.push_back(i);}
        }
        return v;
    }
};