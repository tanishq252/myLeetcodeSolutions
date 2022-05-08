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
        if(root==NULL){
            return;
        }
        inOrder(v, root->left);
        v.push_back(root->val);
        inOrder(v, root->right);
        
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> v, v1;
        inOrder(v, root);
        v1 = v;
        sort(v1.begin(), v1.end());
        set<int> s (v.begin(), v.end());
        if(s.size()!=v.size()){
            return false;
        }
        return v1 == v;
    }
};