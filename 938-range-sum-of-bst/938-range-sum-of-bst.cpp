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
    int s=0;
    
    int height(TreeNode *root){
        if(root==NULL){return 0;}
        else{
            int lh = height(root->left);
            int rh = height(root->right);
            if(lh>rh){
                return (lh+1);
            }else{
                return (rh+1);
            }
        }
    }

    void currentLevel(TreeNode *root, int level, int low, int high){
        if(root==NULL){
            return;}
        if(level == 1){
            int v = (root->val);
            if(v>=low && v<=high){
                s+=v;
            }
        }
        else if(level>1){
            currentLevel(root->left, level-1, low, high);
            currentLevel(root->right, level-1, low, high);
        }
    }

    int printAllLevels(TreeNode *root, int low, int high){
        
        int h = height(root);
        for(int i=1;i<= h;i++){
            currentLevel(root, i, low, high);
        }
        return s;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        s = printAllLevels(root, low, high);
        return s;
    }
};