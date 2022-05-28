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
    void leveltraverse(TreeNode *root, vector<vector<int>> &level,int depth){
        if(root==NULL) return;
        if(depth == level.size()){
            level.push_back({});
        }
        level[depth].push_back(root->val);
        leveltraverse(root->left, level, depth+1);        
        leveltraverse(root->right, level, depth+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        vector<vector<int>> level;
        leveltraverse(root, level, 0);
        for(auto i:level){
            ans.push_back(i[i.size()-1]);
        }
        return ans;
    }
};