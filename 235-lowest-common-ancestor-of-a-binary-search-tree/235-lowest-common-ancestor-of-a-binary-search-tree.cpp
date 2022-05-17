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
    TreeNode *roott;
    void inOrder(TreeNode *root, TreeNode* p,TreeNode* q, vector<pair<int, TreeNode*>> &ancestors){
        if(root==NULL){return;}
        inOrder(root->left, p, q, ancestors);        
        if(root->val >= p->val and root->val <= q->val and nodedepth(roott, p, 0)>=nodedepth(roott, root, 0) and nodedepth(roott, q, 0)>=nodedepth(roott, roott, 0)){
            ancestors.push_back({nodedepth(roott, root, 0),root});
        }
        inOrder(root->right, p, q, ancestors);
    }
    
    int nodedepth(TreeNode *root, TreeNode *node,int depth){
        if(root == node || root==NULL) return 0;
        if(root->val > node->val) {
            return nodedepth(root->left, node, depth)+1;}
        else {
            return nodedepth(root->right, node, depth)+1;}
        return 0;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        roott = root;
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
        inOrder(root, small, large, ancestors);
        vector<int> ans;
        sort(ancestors.begin(), ancestors.end());
        return ancestors[0].second;
    }
};