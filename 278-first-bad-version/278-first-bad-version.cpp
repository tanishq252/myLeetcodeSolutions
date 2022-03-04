// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int fina;
        while(isBadVersion(n)){
            fina = n--;
        }
        return fina;
    }
};