class Solution {
public:
    int binToInt(string s){
        int num = 0;
        int j = 1;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='1'){
                num+=j;
            }
            j*=2;
        }
        return num;
    }
    
    string intToStr(int n){
        string s = "";
        if(n==0) return "0";
        while(n>0){
            s = to_string(n%2)+s;
            n/=2;
        }
        return s;
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        vector<int> v;
        for(auto i:nums){
            v.push_back(binToInt(i));
        }
        sort(v.begin(), v.end());
        int high = v.size()-1, low = 0, mid;
        while(high>=low){
            mid = low+(high-low)/2;
            if(v[mid] == mid){
                low = mid+1;
            }else{
                high = mid - 1;
            }
        }
        string ans = intToStr(low);
        if(ans == "0"){
            string vv(nums[0].size(), '0');
            return vv;
        }
        if(ans.size()<nums[0].size()){
            string vv(nums[0].size()-ans.size(), '0');
            return vv+ans;
        }
        return ans;
    }
};