class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> m;
        int i=0, j = nums.size()-1;
        while(i<=j){
            if(i==j){
                m[nums[i]]++;
                if(m[nums[i]]>=2){
                    return nums[i];
                }
                break;
            }
            m[nums[i]]++; m[nums[j]]++;
            if(m[nums[i]]>=2){return nums[i];}
            else if(m[nums[j]]>=2){return nums[j];}
            i++;j--;
        }
        return 0;
    }
};