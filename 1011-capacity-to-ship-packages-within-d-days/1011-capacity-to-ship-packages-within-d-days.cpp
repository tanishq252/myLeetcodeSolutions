class Solution {
public:
    bool isPossible(int j, vector<int> weights, int days){
        int sum=0, ans=1;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum > j){
                ans++;
                sum = weights[i];
            }
        }
        return (ans <= days) ? true:false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int m = *max_element(weights.begin(), weights.end());
        int s = accumulate(weights.begin(), weights.end(),0);
        int mid;
        // this passed 84/85 cases, the idea here is that we need to perform binary search considering max as low and sum as high and the further process will be same
        while(m<s){
            mid = (s+m)/2;
            if(isPossible(mid, weights, days)){
                // max to mid
                s = mid;
            }else{
                // mid to sum
                m = mid+1;
            }
        }
        return m;
    }
};