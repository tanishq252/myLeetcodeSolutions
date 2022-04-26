class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        
        vector<bool> inMST(n);
        
        pq.push({0,0});
        
        int edgesUsed = 0;
        int totalweights = 0;
        
        while(edgesUsed<n){
            pair<int, int> topEle = pq.top();
            pq.pop();
            
            int curr = topEle.second;
            int weight = topEle.first;
            
            if(inMST[curr]){
                continue;
            }
            
            inMST[curr] = true;
            totalweights+=weight;
            edgesUsed++;
            
            for(int nxtNode = 0;nxtNode<n;nxtNode++){
                if(!inMST[nxtNode]){
                    int nxtWeight = abs(points[curr][0]-points[nxtNode][0])+abs(points[curr][1]-points[nxtNode][1]);
                    pq.push({nxtWeight, nxtNode});
                }
            }
            
        }
        
        
        return totalweights;
    }
};