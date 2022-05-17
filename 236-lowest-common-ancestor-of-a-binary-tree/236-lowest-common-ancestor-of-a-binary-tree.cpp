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
     void getAncestors(TreeNode *root, TreeNode* p, TreeNode* q, int depth, vector<pair<int, TreeNode*>> &ancestors){
        if(root==NULL){
            return;
        }
        getAncestors(root->left,p,q,depth+1, ancestors);        
        if(hasDescendant(root,p,q)){
            ancestors.push_back({depth, root});
        }
        getAncestors(root->right,p,q,depth+1, ancestors);

    }
    
    void InOrder(TreeNode *root, vector<int> &v){
        if(root == NULL){
            return;
        }
        InOrder(root->left, v);
        v.push_back(root->val);
        InOrder(root->right, v);
    }
    
    bool hasDescendant(TreeNode* node, TreeNode *p, TreeNode *q){
        vector<int> v;
        InOrder(node, v);
        return (count(v.begin(), v.end(), p->val)>0 and count(v.begin(), v.end(), q->val)>0 )? true: false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<pair<int, TreeNode*>> ancestors;
        getAncestors(root, p, q, 0, ancestors);
        sort(ancestors.begin(), ancestors.end());
        return ancestors[ancestors.size()-1].second;
    }
    
   
};