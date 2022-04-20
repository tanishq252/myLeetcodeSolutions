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
    void preOrder(vector<int> &v, TreeNode *root){
        if(root==NULL){
            v.push_back(-101);
            return;}
        v.push_back(root->val);
        preOrder(v, root->left);
        preOrder(v, root->right);
    }
    
    void swap(TreeNode **n1, TreeNode **n2){
        TreeNode *t = *n1;
        *n1 = *n2;
        *n2 = t;
    }
    
    void invert(TreeNode *root){
        if(root==NULL){return;}
        invert(root->left);
        invert(root->right);
        swap(&(root->left), &(root->right));
    }
    
    bool isSymmetric(TreeNode* root) {
        vector<int> l,r;
        invert(root->right);
        preOrder(l, root->right);
        preOrder(r, root->left);
        return r==l;
    }
};