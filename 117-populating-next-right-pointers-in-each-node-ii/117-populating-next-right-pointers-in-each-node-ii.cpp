/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void levelOrder(Node *root, vector<vector<Node *>> &ans, int depth){
        if(root==NULL){
            return;
        }
        if(ans.size() == depth){
            ans.push_back({});
        }
        ans[depth].push_back(root);
        levelOrder(root->left, ans, depth+1);        
        levelOrder(root->right, ans, depth+1);
    }
    
    Node* connect(Node* root) {
        vector<vector<Node *>> v;
        levelOrder(root, v, 0);
        for(auto i:v){
            for(int j=0;j<i.size()-1;j++){
                i[j]->next = i[j+1];
            }
            i[i.size()-1]->next = NULL;
        }
        return root;
    }
};