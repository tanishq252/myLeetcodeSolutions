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
    vector<vector<int>> v;
    
    void LevelOrder(TreeNode *root, int depth){
        if(root==NULL){
            return;
        }else if(v.size() == depth){
            v.push_back(vector<int> ());
        }
        v[depth].push_back(root->val);
        LevelOrder(root->left, depth+1);
        LevelOrder(root->right, depth+1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        LevelOrder(root, 0);
        vector<double> ans;
        for(auto i:v){
            double s = accumulate(i.begin(), i.end(), 0.0);
            ans.push_back(s/i.size());
        }
        return ans;
    }
};