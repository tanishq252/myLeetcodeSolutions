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
    void levelOrder(vector<vector<int>> &lvl, TreeNode *root, int level){
        if(root==NULL){
            return;
        }
        if(lvl.size() == level){
            lvl.push_back({});
        }
        lvl[level].push_back(root->val);
        levelOrder(lvl, root->left, level+1);        
        levelOrder(lvl, root->right, level+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> lvl;
        vector<int> ans;
        levelOrder(lvl, root, 0);
        for(auto i:lvl){
            ans.push_back(i[i.size()-1]);
        }
        return ans;
    }
};