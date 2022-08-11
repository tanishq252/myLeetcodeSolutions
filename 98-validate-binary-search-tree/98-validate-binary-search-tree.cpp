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
    vector<int> v, v1;
    
    void inOrder(TreeNode *root){
        if(root==NULL) return;
        inOrder(root->left);
        v.push_back(root->val);
        inOrder(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        v1 = v;
        set<int> s(v.begin(), v.end());
        if(s.size()!=v.size()) return false;
        sort(v1.begin(), v1.end());
        return v==v1;
    }
};