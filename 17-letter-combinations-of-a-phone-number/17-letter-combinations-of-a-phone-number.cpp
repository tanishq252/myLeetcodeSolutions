class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits==""){
            return ans;
        }
        unordered_map<char, vector<string>> m = {{'2',{"a", "b", "c"}}, {'3',{"d", "e", "f"}}, 
{'4',{"g", "h", "i"}}, {'5',{"j", "k", "l"}}, {'6',{"m", "n", "o"}}, {'7',{"p", "q", "r", "s"}},        {'8',{"t", "u", "v"}}, {'9',{"w", "x", "y", "z"}}};
        if(digits.length()==1){
            for(auto i:m[digits[0]]){
                ans.push_back(i);
            }
        }else if(digits.length()==2){
            for(auto i:m[digits[0]]){
                for(auto j:m[digits[1]]){
                    ans.push_back(i+j);
                }
            }
        }else if(digits.length()==3){
            for(auto i:m[digits[0]]){
                for(auto j:m[digits[1]]){
                    for(auto k:m[digits[2]]){
                        ans.push_back(i+j+k);
                    }
                }
            }
        }else if(digits.length()==4){
            for(auto i:m[digits[0]]){
                for(auto j:m[digits[1]]){
                    for(auto k:m[digits[2]]){
                        for(auto l:m[digits[3]]){
                            ans.push_back(i+j+k+l);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};