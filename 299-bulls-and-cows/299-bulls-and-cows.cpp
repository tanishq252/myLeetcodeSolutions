class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> secmp(10, 0);        
        vector<int> guessmp(10, 0);
        int bulls = 0, cows = 0;
        for(int i=0;i<guess.length();i++){
            if(secret[i] == guess[i]){
                bulls++;
            }
            else{
                secmp[secret[i]-'0']++;                
                guessmp[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            if(secmp[i]>0 and guessmp[i]>0){
                cows+=min(guessmp[i], secmp[i]);
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};