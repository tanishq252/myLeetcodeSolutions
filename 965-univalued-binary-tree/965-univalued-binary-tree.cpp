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
    
    void inOrder(set<int> &s, TreeNode* root){
        if(root==NULL){return;}
        inOrder(s, root->left);
        s.insert(root->val);
        inOrder(s, root->right);
    }
    
    bool isUnivalTree(TreeNode* root) {
        set<int> s;
        inOrder(s, root);
        return (s.size()==1)?true:false;
    }
};