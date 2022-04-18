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
    
    void inOrder(vector<int> &v, TreeNode* root){
        if(root==NULL){return ;}
        inOrder(v, root->left);        
        v.push_back(root->val);
        inOrder(v, root->right);

    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inOrder(v, root);
        sort(v.begin(), v.end());
        return v[k-1];
        
    }
};