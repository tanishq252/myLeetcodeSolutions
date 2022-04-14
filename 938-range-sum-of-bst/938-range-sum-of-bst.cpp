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

    void currentLevel(vector<int> &v, TreeNode *root, int level){
        if(root==NULL){
            return;}
        if(level == 1){v.push_back(root->val);}
        else if(level>1){
            currentLevel(v, root->left, level-1);
            currentLevel(v, root->right, level-1);
        }
    }

    vector<int> printAllLevels(TreeNode *root){
        vector<int> v;
        int h = height(root);
        for(int i=1;i<= h;i++){
            currentLevel(v, root, i);
        }
        return v;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> v = printAllLevels(root);
        sort(v.begin(), v.end());
        int s=0;
        for(auto i:v){
            cout<<i<<" ";
        }
        for(int i=0;i<v.size();i++){
            if(v[i] == low){
                while(v[i]<=high){
                    if(v[i]==high){
                        s+=v[i];
                        return s;
                    }
                    s+=v[i];
                    i++;
                }
                return s;
            }
        }
        return s;
    }
};