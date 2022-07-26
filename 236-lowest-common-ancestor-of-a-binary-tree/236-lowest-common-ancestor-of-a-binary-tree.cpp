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
//     priority_queue<pair<int, TreeNode*>> pq;
    
//     void findDescendants(TreeNode *root, TreeNode *p, TreeNode *q, int depth){
//         if(root==NULL) return;
//         map<TreeNode*, int> mp;
//         checkNodes(root, p, q, mp);
//         if(mp.find(q)!=mp.end() and mp.find(p)!=mp.end()){
//             pq.push({depth, root});
//         }
//         mp.clear();
//         findDescendants(root->left, p, q, depth+1);        
//         findDescendants(root->right, p, q, depth+1);
//     }
    
//     void checkNodes(TreeNode *root, TreeNode *p, TreeNode *q, map<TreeNode *, int> &mp){
//         if(root==NULL) return;
//         mp[root]++;
//         if(mp.find(q)!=mp.end() and mp.find(p)!=mp.end()){
//             cout<<"fond\n";
//             return;
//         }
//         checkNodes(root->left, p, q, mp);        
//         checkNodes(root->right, p, q, mp);
//     }
    
    priority_queue<pair<int, TreeNode*>> ancestors;
     void getAncestors(TreeNode *root, TreeNode* p, TreeNode* q, int depth){
        if(root==NULL){
            return;
        }
        getAncestors(root->left,p,q,depth+1);        
        if(hasDescendant(root,p,q)){
            ancestors.push({depth, root});
        }
        getAncestors(root->right,p,q,depth+1);

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
        getAncestors(root, p, q, 0);
        return ancestors.top().second;
    }
};