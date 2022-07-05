class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 2){
            return (abs(nums[0]-nums[1])==1)?2:1;
        }
        int mx=1;
        set<int> s(nums.begin(), nums.end());
        vector<int> nm(s.begin(), s.end());
        sort(nm.begin(), nm.end());
        int c=1, i=0;
        while(i<nm.size()-1){
            if(abs(nm[i+1]-nm[i]) == 1){
                c++;
            }
            else{
                mx = (c>mx)?c:mx;
                c=1;
            }
            i++;
        }
        mx = (c>mx)?c:mx;
        return mx;
    }
};