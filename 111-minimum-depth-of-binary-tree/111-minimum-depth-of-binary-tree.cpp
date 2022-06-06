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
    int mindepth = 0;
    
    void levelOrder(TreeNode *root,int depth){
        if(root==NULL) {mindepth = depth-1; return;}
        levelOrder(root->left, depth+1);
        levelOrder(root->right, depth+1);
    }
    
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if(root->left == NULL) return r+1;
        if(root->right==NULL) return l+1;
        return min(l,r)+1;
        
    }
};