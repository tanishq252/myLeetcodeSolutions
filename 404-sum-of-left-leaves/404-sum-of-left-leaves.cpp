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
    vector<int> v;
    void inOrder(TreeNode *root, vector<int> &v){
        if(root==NULL){return;}
        inOrder(root->left, v);
        if(root->left==NULL){
            // v.push_back(0);
        }
        else{
            if(root->left->left == NULL && root->left->right == NULL){
                v.push_back(root->left->val);
            }
            else{}
        }
        inOrder(root->right, v);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        inOrder(root, v);
        return accumulate(v.begin(), v.end(), 0);
    }
};