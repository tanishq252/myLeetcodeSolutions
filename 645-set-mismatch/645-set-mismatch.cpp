class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v = {0,0};
        for(int i=0;i<nums.size();i++){
            int c = count(nums.begin(), nums.end(), i+1);
            if(c==2){v[0]=i+1;}
            else if(c==0){
                v[1] = i+1;
            }
            if(v[0]!=0 && v[1]!=0){return v;}
        }
        return v;
    }
};