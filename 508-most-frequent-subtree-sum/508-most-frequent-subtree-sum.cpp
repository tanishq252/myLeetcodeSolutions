/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> sums;
    int initializeSubtreeSum(TreeNode *root){
        if(root==NULL) return 0;
        int sum = root->val;
        sum+= initializeSubtreeSum(root->left);
        sum+= initializeSubtreeSum(root->right);
        root->val = sum;
        sums.push_back(sum);
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int subtreeSums = initializeSubtreeSum(root);
        map<int, int> mp;
        int maxFreq=INT_MIN;
        for(auto i:sums){
            mp[i]++;
            maxFreq = max(maxFreq, mp[i]);
        }
        set<int> ans;
        for(auto i:sums){
            if(mp[i] == maxFreq){
                ans.insert(i);
            }
        }
        return vector<int> (ans.begin(), ans.end());
    }
};