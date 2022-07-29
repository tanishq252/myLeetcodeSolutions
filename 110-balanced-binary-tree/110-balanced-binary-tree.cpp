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
    bool ans = true;
    
    int findHeight(TreeNode *root){
        if(root==NULL) return 0;
        if(!ans) return 0;
        if(root->left == NULL and root->right == NULL ) return 1;
        int l=0, r=0;
        if(root->left!=NULL) l = findHeight(root->left);        
        if(root->right!=NULL) r = findHeight(root->right);
        if(abs(l-r) > 1) {ans = false; return 0;}
        return max(l, r)+1;
    }
    
    int depth(TreeNode *root){
        if(root == NULL) return 0;
        return max(depth(root->left), depth(root->right))+1;
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        
        int l = depth(root->left);        
        int r = depth(root->right);
        
        return abs(l-r)<=1 and isBalanced(root->left) and isBalanced(root->right);

    }
};