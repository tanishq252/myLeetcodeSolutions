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
    unordered_map<TreeNode *, int> memoMap;
    
    int dfs(TreeNode *root){
        if(root==NULL) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        memoMap[root->left] = left;
        memoMap[root->right] = right;
        int ll = (root->left!=NULL) ? memoMap[root->left->left]:0;        
        int lr = (root->left!=NULL) ? memoMap[root->left->right]:0;
        int rr = (root->right!=NULL) ? memoMap[root->right->right]:0;
        int rl = (root->right!=NULL) ? memoMap[root->right->left]:0;
        return max(left+right, root->val+ll+rr+lr+rl);
    }
    
    int rob(TreeNode* root) {
        return dfs(root);
    }
};