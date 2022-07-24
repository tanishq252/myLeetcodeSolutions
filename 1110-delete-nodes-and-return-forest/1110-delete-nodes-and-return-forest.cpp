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
    TreeNode *deleteNode(TreeNode *root, vector<int>& to_delete, vector<TreeNode*>& ans){
        if(root==NULL) return root;
        if(count(to_delete.begin(), to_delete.end(), root->val) == 1){
            root->right = deleteNode(root->right, to_delete, ans);
            if(root->right!=NULL){
                ans.push_back(root->right); 
            }
            root->left = deleteNode(root->left, to_delete, ans);
            if(root->left!=NULL){
                ans.push_back(root->left); 
            }
            return NULL;
        }
        root->left = deleteNode(root->left, to_delete, ans);        
        root->right = deleteNode(root->right, to_delete, ans);
        return root;

    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        root = deleteNode(root, to_delete, ans);
        if(root!=NULL){
            ans.push_back(root);
        }
        return ans;
    }
};