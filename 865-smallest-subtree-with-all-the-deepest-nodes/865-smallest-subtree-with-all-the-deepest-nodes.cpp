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
    int deepest = 0;
    TreeNode *smallest=NULL;
    int depthValue(TreeNode *root, int depth){
        deepest = max(depth, deepest);
        if(root == NULL){
            return depth;
        }
        int left = depthValue(root->left, depth+1);        
        int right = depthValue(root->right, depth+1);
        if(left == deepest and right == deepest){
            smallest = root;
        }
        return max(left, right);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        depthValue(root, 0);
        return smallest;
    }
};