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
    void traverse(TreeNode *root){
        if(root == NULL) return;
        v.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        traverse(root);
        sort(v.begin(), v.end());
        int n=v.size();
        int i=0, j=n-1;
        while(i<j){
            int sum = v[i]+v[j];
            if(sum==k) return true;
            else if(sum<k) i++;
            else if(sum>k) j--;
        }
        return false;
    }
};