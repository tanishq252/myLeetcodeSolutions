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
    int ans=0;
    void dfs(TreeNode *root, string s){
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL){
            s+=to_string(root->val);
            ans+=stoi(s);
            return;
        }
        s+=to_string(root->val);
        dfs(root->left, s);        
        dfs(root->right, s);
    }
    int sumNumbers(TreeNode* root) {
        string s="";
        dfs(root, s);
        return ans;
    }
};