class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        priority_queue<long long int> hor;        
        priority_queue<long long int> ver;
        sort(horizontalCuts.begin(), horizontalCuts.end());                                   sort(verticalCuts.begin(), verticalCuts.end());

        hor.push(horizontalCuts[0]);        
        ver.push(verticalCuts[0]);
        
        for(int i=0;i<horizontalCuts.size()-1;i++){
            hor.push(horizontalCuts[i+1]-horizontalCuts[i]);
        }
        
        hor.push(h-horizontalCuts[horizontalCuts.size()-1]);  
        
        for(int i=0;i<verticalCuts.size()-1;i++){
            ver.push(verticalCuts[i+1]-verticalCuts[i]);
        }
        
        ver.push(w-verticalCuts[verticalCuts.size()-1]);  

        return  (ver.top()*hor.top())%1000000007;

    }
};