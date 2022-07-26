class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        //priority queue to store max H-index
        priority_queue<int> pq;
        sort(citations.begin(), citations.end());
        for(int i=0;i<=citations[n-1];i++){
            
            //lower bound of current value 
            int lb = lower_bound(citations.begin(), citations.end(), i)-citations.begin();
            
            //upper bound of current value 
            int ub = upper_bound(citations.begin(), citations.end(), i)-citations.begin();

            //considering the values between lower bound and upper found\
            //considering either the current value or the papers after current value

            for(int j=n-ub;j<=n-lb;j++){
                if(i == j){
                    pq.push(i);         
                }
            }
        }
        return (!pq.empty()) ? pq.top() : (citations[0] ==0) ? citations[n-1] : citations[0];
    }
};