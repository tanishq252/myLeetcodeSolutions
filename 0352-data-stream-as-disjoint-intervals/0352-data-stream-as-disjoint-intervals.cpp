class SummaryRanges {
public:
    vector<vector<int>> ans;
    set<int> v;
    
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        v.insert(value);
    }
    
    void mergeIntervals(){
        ans = {};int i=0,j=0,fi=0;
        vector<int> vec(v.begin(), v.end());
        // if(vec.size())
        while(i<vec.size()){
            j=i+1;
            if(j==vec.size()) break;
            while(vec[j]==vec[j-1]+1){
                j++;
                if(j==vec.size()) break;
            }
            ans.push_back({vec[i], vec[j-1]});
            i=j;
        }
        if(j!=i) ans.push_back({vec[i], vec[i]});
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