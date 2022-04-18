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
    void inOrder(set<int> &v, TreeNode* root){
        if(root==NULL){return ;}
        inOrder(v, root->left);        
        v.insert(root->val);
        inOrder(v, root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> v;
        inOrder(v, root);
        if(v.size()==1){return -1;}
        vector<int> ans(v.begin(), v.end());
        sort(ans.begin(), ans.end());
        return ans[1];
    }
};