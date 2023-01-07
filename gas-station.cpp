// https://leetcode.com/problems/gas-station/description/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        // O(n)
        int n = cost.size();
        int total = 0, preSum = 0, ans=0;

        for(int i=0;i<n;i++){
            total += (gas[i]-cost[i]);
            preSum += (gas[i]-cost[i]);
            if(preSum <0){
                preSum=0;
                ans = i+1;
            }
        }

        return (total >= 0) ? ans : -1;

        // Accepted solution O(n^2)
        // int n=cost.size();
        // vector<int> diff(n);
        // int in, mx = INT_MIN;
        // bool allPos = false;
        // for(int i=0;i<n;i++){
        //     diff[i] = gas[i]-cost[i];
        //     mx = max(mx, gas[i]-cost[i]);
        //     if(gas[i] < cost[i]) allPos = true;
        // }
        // if(!allPos) return 0;
        // if(mx < 0) return -1;
        // for(int i=0;i<n;i++){
        //     int capacity;
        //     if(diff[i]>0){
        //         capacity = diff[i];
        //         int ind = i, c=diff[i], f=0;

        //         while((ind+1)%n != i){
        //             c += diff[(ind+1)%n];
        //             if(c<0) {f=1;break;}
        //             ind++;
        //         }
        //         if(f==0) return i;
        //     }
        // }
        // return -1;
    }
};