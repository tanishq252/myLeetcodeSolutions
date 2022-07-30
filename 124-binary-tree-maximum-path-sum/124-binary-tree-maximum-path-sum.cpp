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
    int ans = INT_MIN;
    
    int maxFromChild(TreeNode* root){
        if(root==NULL) return 0;
        
        int maxLeftPath = maxFromChild(root->left);
        int maxRightPath = maxFromChild(root->right);
        
        int maxEitherPath = max(root->val, root->val+max(maxLeftPath, maxRightPath));

        int maxPath = max(maxEitherPath, root->val+maxLeftPath+maxRightPath);
        
        ans = max(ans, maxPath);
        
        return maxEitherPath;
        
    }
    
    int maxPathSum(TreeNode* root) {
        maxFromChild(root);
        return ans;
    }
};