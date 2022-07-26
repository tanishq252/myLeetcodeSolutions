class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        priority_queue<int> pq;
        sort(citations.begin(), citations.end());
        int ind = lower_bound(citations.begin(), citations.end(), 2)-citations.begin();
        for(int i=0;i<=citations[n-1];i++){
            int lb = lower_bound(citations.begin(), citations.end(), i)-citations.begin();
            if(i == n-lb or i==n-lb-1){
                pq.push(i);         
                // break;
                }
            int ub = upper_bound(citations.begin(), citations.end(), i)-citations.begin();
            cout<<n-lb<<" "<<i<<"\n";
            if(i == n-ub){
                pq.push(i);         
                // break;
            }
            for(int j=n-ub;j<=n-lb;j++){
                if(i == j){
                pq.push(i);         
                // break;
            }
            }
            // cout<<i<<" "<<lb<<"\n";
        }
        // cout<<pq.top();
        return (!pq.empty()) ? pq.top() : (citations[0] ==0) ? citations[n-1] : citations[0];
        // return 0;
    }
};