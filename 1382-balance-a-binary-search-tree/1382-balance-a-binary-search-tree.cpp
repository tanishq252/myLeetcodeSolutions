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
    void inOrder(TreeNode *root, vector<int> &v){
        if (root == NULL) return;
        inOrder(root->left, v);        
        v.push_back(root->val);
        inOrder(root->right, v);
    }
    
    TreeNode *balanceBST(int low, int high, vector<int> &v){
        if(low>high) return NULL;
        int mid = low + (high-low)/2;
        TreeNode *root = new TreeNode(v[mid]);
        root->left = balanceBST(low, mid-1, v);        
        root->right = balanceBST(mid+1, high, v);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inOrder(root, v);
        TreeNode *ans = balanceBST(0, v.size()-1, v);
        return ans;
    }
};