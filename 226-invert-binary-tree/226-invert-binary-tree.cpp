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
    void swap(TreeNode **n1, TreeNode **n2){
        TreeNode *t = *n1;
        *n1 = *n2;
        *n2 = t;
    }
    
    void preOrderInvert(TreeNode *root){
        if(root==NULL){return;}
        preOrderInvert(root->left);
        preOrderInvert(root->right);
        swap(&(root->left), &(root->right));
    }
    
    TreeNode* invertTree(TreeNode* root) {
        preOrderInvert(root);
        return root;
    }
};