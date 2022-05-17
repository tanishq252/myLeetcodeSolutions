/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void inOrder(TreeNode *root, TreeNode* p,TreeNode* q, vector<pair<int, TreeNode*>> &ancestors, int depth){
        if(root==NULL){return;}
        inOrder(root->left, p, q, ancestors, depth+1);        
        if(root->val >= p->val and root->val <= q->val){
            ancestors.push_back({depth,root});
        }
        inOrder(root->right, p, q, ancestors, depth+1);
    }

    bool findDescedant(){
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<pair<int, TreeNode*>> ancestors;
        TreeNode* small;
        TreeNode *large;
        if(p->val > q->val){
            small = q;
            large = p;
        }else if(p->val < q->val){
            small = p;
            large = q;
        }
        cout<<small<<" "<<large;
        inOrder(root, small, large, ancestors, 0);
        vector<int> ans;
        sort(ancestors.begin(), ancestors.end());
        return ancestors[0].second;
    }
};