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
    void recursiveSearch(TreeNode *root,int val, TreeNode **ans){
        if(root==NULL) return;
        if(root->val==val){
            *ans = root;
            return;
        }else if(root->val > val){
            recursiveSearch(root->left, val, ans);
        }else if(root->val < val){
            recursiveSearch(root->right, val, ans);
        }
        // else{
        //     return;
        // }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *ans=NULL;
        recursiveSearch(root, val, &ans);
        return ans;
        
    }
};