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
    void levelOrder(TreeNode *root, int depth, vector<vector<int>> &ans){
        if(root==NULL) return;
        if(ans.size() == depth) {
            ans.push_back({});
        }
        ans[depth].push_back(root->val);
        levelOrder(root->left, depth+1, ans);            
        levelOrder(root->right, depth+1, ans);
      
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(root, 0, ans);
        for(int i=0;i<ans.size();i++){
            if(i%2==1){reverse(ans[i].begin(), ans[i].end());}
        }
        return ans;
    }
};