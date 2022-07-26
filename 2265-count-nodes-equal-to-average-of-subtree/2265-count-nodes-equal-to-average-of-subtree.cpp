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
    int ans = 0;
    
    void check(TreeNode *root){
        if(root==NULL) return;
        vector<int> v;
        Inorder(root, v);
        if(accumulate(v.begin(), v.end(), 0) / v.size() == root->val){
            ans++;
        }
        check(root->left);        
        check(root->right);

    }
    
    void Inorder(TreeNode *root, vector<int> &v){
        if(root==NULL) return;
        Inorder(root->left, v);        
        v.push_back(root->val);
        Inorder(root->right, v);
    }
    
    int averageOfSubtree(TreeNode* root) {
        check(root);
        return ans;
    }
};