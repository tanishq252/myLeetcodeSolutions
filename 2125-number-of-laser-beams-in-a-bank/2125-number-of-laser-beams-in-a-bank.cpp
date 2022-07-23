class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        if(bank.size() == 1) return 0;
        vector<int> beams;
        for(int i = 0;i<bank.size();i++){
            int c = count(bank[i].begin(), bank[i].end(), '1');
            if(c){
                beams.push_back(c);
            }
        }
        int ans;
        if(beams.size()){
            for(int i=0;i<beams.size() - 1;i++){
                beams[i]*=beams[i+1];
                cout<<beams[i]<<" ";
            }
            return accumulate(beams.begin(), beams.end()-1, 0);
        }
        return 0;
    }
};