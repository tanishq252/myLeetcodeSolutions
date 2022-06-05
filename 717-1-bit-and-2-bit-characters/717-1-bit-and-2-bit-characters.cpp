class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i=0;
        while(i<bits.size()){
            if(bits[i] == 1){
                i+=2;
                if(i==bits.size()){break;}
            }
            else{
                if(i==bits.size()-1){break;}
                i++;
            }
        }
        return i==bits.size()-1;
    }
};