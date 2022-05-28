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
    
    void levelOrder(TreeNode *root, vector<vector<int>> &level, int depth){
        if(root==NULL){return;}
        if(level.size() == depth){
            level.push_back({});
        }
        level[depth].push_back(root->val);
        levelOrder(root->left, level, depth+1);        
        levelOrder(root->right, level, depth+1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> level;
        levelOrder(root, level, 0);
        vector<int> ans;
        for(auto i:level){
            ans.push_back(*max_element(i.begin(), i.end()));
        }
        return ans;
    }
};