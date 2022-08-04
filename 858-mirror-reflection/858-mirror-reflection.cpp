class Solution {
public:
    int mirrorReflection(int p, int q) {
        // as per the given question we can find a pattern that if the side of square room is even then whatever value of q is there the final reveptor will be 2
        // else if p is odd then there are two probabilities:
        // q is even: if we draw a room and receptor for this case then we can figure out that the final receptor will be 0
        // q is odd: for this case then we can figure out that the final receptor will be 1
        // if p and q are equal then a line at 45 degrees passes from the initial point and reaches receptor 1
        
        // the most important thing to consider before we proceed with the above approach is that, p and q can have mutual factors at the beginning so if we divide both the numbers with their gcd then the above explained pattern works efficiently to satisfy the problem statement
        
        // gcd of p and q using inbuilt function
        int g = __gcd(p,q);
        p/=g;
        q/=g;
        
        // logic as per the above explained pattern
        if(p==q) return 1;
        
        if(p%2==0){
            return 2;
        }else{
            if(q%2==0){
                return 0;
            }else{
                return 1;
            }
        }
        return 0;
    }
};