class SummaryRanges {
public:
    vector<vector<int>> ans;
    set<int> vec;
    
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        vec.insert(value);
    }
    
    void mergeIntervals(){
        ans = {};int i=-1,j=-1;
        for(auto &v:vec){
            if(i<0){
                i=j=v;
            }else if(v == j+1){
                j=v;
            }else{
                ans.push_back({i,j});i=j=v;
            }
        }
        ans.push_back({i,j});
    }
    
    vector<vector<int>> getIntervals() {
        mergeIntervals();
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */