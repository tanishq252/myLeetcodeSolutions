class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<pair<int, int>> targets;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int l = i+1;
            int r = nums.size()-1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(targets.size()==0){
                    targets.push_back({sum, abs(target-sum)});
                }else{
                    if(sum == target){
                        return target;
                    }else if(sum>target){
                        if(targets[targets.size()-1].second > abs(sum-target)){
                            targets.push_back({sum, abs(target-sum)});
                        }
                        r--;
                    }else if(sum<target){
                        if(targets[targets.size()-1].second > abs(sum-target)){
                            targets.push_back({sum, abs(target-sum)});
                        }
                        l++;
                    }
                }
            }
        }
        return targets[targets.size()-1].first;
    }
};