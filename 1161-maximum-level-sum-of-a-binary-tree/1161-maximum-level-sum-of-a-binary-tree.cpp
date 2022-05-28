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
    
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> level;
        int max = INT_MIN;
        leveltraverse(root, level, 0);
        int depth = 0;
        for(int i=0;i<level.size();i++){
            int sum = accumulate(level[i].begin(), level[i].end(), 0);
            if(sum>max){
                max = sum;
                depth = i;
            }
        }
        return depth+1;
    }
};