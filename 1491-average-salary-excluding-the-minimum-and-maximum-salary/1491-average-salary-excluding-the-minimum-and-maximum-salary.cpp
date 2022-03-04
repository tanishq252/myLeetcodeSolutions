class Solution {
public:
    double average(vector<int>& salary) {
        double s = 0.00000;
        sort(salary.begin(), salary.end());
        s = accumulate(salary.begin()+1, salary.end()-1,s);
        return (s/(salary.size()-2));
    }
};