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
    void inOrder(vector<int> &v, TreeNode* root){
        if(root==NULL){return;}
        inOrder(v, root->left);
        v.push_back(root->val);
        inOrder(v, root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        inOrder(v, root);
        sort(v.begin(), v.end());
        unordered_map<int, int> m;
        vector<pair<int, int>> vec;
        for(int i=0;i<v.size();i++){
            m[v[i]]++;
        }
        int mx = INT_MIN;
        for(int i=0;i<v.size();i++){
            vec.push_back(make_pair(m[v[i]], v[i]));
            mx = (m[v[i]]>mx)?m[v[i]]:mx;
        }
        cout<<mx;
        sort(vec.begin(), vec.end());
        set<int> ans;
        for(int i=vec.size()-1;i>=0;i--){
            if(vec[i].first==mx){ans.insert(vec[i].second);}
        }
        vector<int> a(ans.begin(), ans.end());
        return a;
    }
};