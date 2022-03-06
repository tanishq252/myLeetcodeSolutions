class Solution {
public:
    int gcd(int n, int s){
        return s == 0 ? n : gcd(s, n % s);   
        }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = gcd(nums[n-1], nums[0]);
        return m;

    }
};