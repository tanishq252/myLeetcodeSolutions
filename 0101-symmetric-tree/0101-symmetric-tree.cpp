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
    vector<int> l,r;
    void tleft(TreeNode *root){
        if(root == NULL) {l.push_back(-1);return;}
        l.push_back(root->val);
        tleft(root->left);        
        tleft(root->right);
    }
    void tright(TreeNode *root){
        if(root == NULL) {r.push_back(-1);return;}
        r.push_back(root->val);
        tright(root->right);        
        tright(root->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        tleft(root->left);        
        tright(root->right);
        return (l == r);
    }
};