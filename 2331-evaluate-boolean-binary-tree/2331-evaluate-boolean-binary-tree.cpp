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
    void postOrder(TreeNode *root){
        if(root == NULL) return;
        postOrder(root->left);
        postOrder(root->right);
        if(root->left!=NULL and root->right!=NULL ){
            if(root->val == 2){
                root->val = root->right->val or root->left->val;
            }else{
                root->val = root->right->val and root->left->val;
            }
        }
    }
    
    bool evaluateTree(TreeNode* root) {
        postOrder(root);
        return root->val == 0 ? false:true;
    }
};