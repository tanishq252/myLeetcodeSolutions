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
    vector<vector<TreeNode*>> v;
    bool ans=true;
    void lvlOrder(TreeNode *root, int d){
        if(root == NULL) {
            return;
        }
        if(v.size() == d) v.push_back({});
        v[d].push_back(root);
        lvlOrder(root->left, d+1);
        lvlOrder(root->right, d+1);
    }
    bool isCompleteTree(TreeNode* root) {
        lvlOrder(root, 0);
        if(v.size()==1) return true;
        vector<int> vec;
        for(int i=0;i<v.size()-1;i++){
            if(v[i].size()!=pow(2,i)) return false;
        }
        for(auto &i:v[v.size()-2]){
            if(i->left!=NULL){
                vec.push_back(i->left->val);
            }else{
                vec.push_back(-1);
            }

            if(i->right!=NULL){
                vec.push_back(i->right->val);
            }else{
                vec.push_back(-1);
            }
        }
        int ind=-1;
        for(int i=0;i<vec.size();i++){
            if(vec[i] == -1){
                ind = i;break;
            }
        }
        if(ind!=-1){
            for(int i=ind;i<vec.size()-1;i++){
                if(vec[i]!=vec[i+1]) return false;
            }
        }
        return true;
    }
};