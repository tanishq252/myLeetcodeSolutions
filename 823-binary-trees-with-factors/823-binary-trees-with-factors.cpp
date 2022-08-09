class Solution {
public:
    // Provided logic comprises of working with factors of given number ans storing them in a hashmap which helps to achieve dynamic programming 
    // Initially we create a map and keep on updating frequency as 1 for all elements in the given array, indicating that every element forms an independent tree
    // Further we traverse through the whole array to check the factors of the element
    // If we find one factor we have to check whether there is another factor available in the given array, whose product with current factor is the current element
    // If we find such a pair then we multiply number of trees of both the elements and finally multiply it with 2 becasue one node can have 2 possibilities of trees, and add it to the number of trees of current element
    // Further we check whether the square root of element is there or not, if it exists then we multiply the square root with itself and add it to number of trees
    // Finally we calculate total number of trees for all elements and the above dicussed logic satisfies all the test cases
    int mod = 1000000007;
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int, long long> mp;
        sort(arr.begin(), arr.end());
        for(auto i:arr){
            mp[i]=1;
        }
        for(int i=0;i<arr.size();i++){
            for(int j=2;j<sqrt(arr[i]);j++){
                if(arr[i]%j == 0 and (j * (arr[i]/j) == arr[i])){
                    if(mp.find(j)!=mp.end() and mp.find(arr[i]/j)!=mp.end()){
                        mp[arr[i]]+= (((((mp[j]%mod)*(mp[arr[i]/j]%mod))%mod)*2)%mod);
                    }
                }
            }
            if(int(sqrt(arr[i]))*int(sqrt(arr[i])) == arr[i] and mp.find(sqrt(arr[i]))!=mp.end()){
                mp[arr[i]]+= (((mp[sqrt(arr[i])]%mod)*(mp[sqrt(arr[i])])%mod)%mod);
            }
            
        }
        
        //here int gives wrong answer since the number of trees can exceed the integer 
        long s = 0;
        for(auto i:mp){
            s+= (i.second);
        }
        
        //mod of the final answer else it does not return an integer
        return s%mod;
    }
};