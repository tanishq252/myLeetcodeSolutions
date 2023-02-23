class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<vector<int>> vec;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            vec.push_back({capital[i], profits[i]});
        }
        sort(vec.begin(), vec.end());
        int p=0;
        while(k--){
            while(p<n and vec[p][0]<=w){
                pq.push(vec[p][1]);
                p++;
            }
            if(pq.empty()){
                break;
            }
            w+=pq.top();
            pq.pop();
        }
        return w;

        // logic is working perfectly fine to satisfy 32/35 test cases

        // int maxProfit = *max_element(profits.begin(), profits.end());
        // int maxCap = *max_element(capital.begin(), capital.end());
        // vector<priority_queue<int>> v(maxCap+1);
        // for(int i=0;i<capital.size();i++){
        //     v[capital[i]].push(profits[i]);
        // }
        // int cap = w;
        // while(k--){
        //     int mxp = INT_MIN, ind=-1;
        //     for(int i=0;i<=min(maxCap, cap);i++){
        //         if(!v[i].empty()){
        //             if(mxp < v[i].top()){
        //                 mxp = v[i].top();
        //                 ind = i;
        //             }
        //         }
        //     }
        //     v[ind].pop();
        //     cap+=mxp;
        // }
        // return cap;

    }
};