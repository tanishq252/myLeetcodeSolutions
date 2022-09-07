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
    string traverse(TreeNode *root){
        if(root == NULL){
            return "";
        }
        
        if(root->left==NULL and root->right==NULL){
            return to_string(root->val)+"";
        }
        // if(root->left == NULL){
        //     return to_string(root->val)+"("+traverse(root->right)+")";
        // }
        if(root->right == NULL){
            return to_string(root->val)+"("+traverse(root->left)+")";
        }
        return to_string(root->val)+"("+traverse(root->left)+")"+"("+traverse(root->right)+")";
    }
    string tree2str(TreeNode* root) {
        string s = traverse(root);
        return s;
    }
};