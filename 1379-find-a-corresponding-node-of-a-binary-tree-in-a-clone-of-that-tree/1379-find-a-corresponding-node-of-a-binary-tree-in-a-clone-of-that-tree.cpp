/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void inOrder(TreeNode *root, TreeNode *target, vector<TreeNode*> &v){
        if(root==NULL){return;}
        inOrder(root->left, target, v);    
        if(root->val == target->val){v.push_back(root);return;}
        inOrder(root->right, target, v);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        vector<TreeNode*> v;
        inOrder(cloned, target, v);
        return v[0];
    }
};