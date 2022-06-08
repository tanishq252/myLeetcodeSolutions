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
    void lvlOrder(Node *root, vector<vector<Node*>> &lvl, int depth){
        if(root==NULL) return;
        if(lvl.size() == depth){
            lvl.push_back({});
        }
        lvlOrder(root->left, lvl, depth+1);
        lvl[depth].push_back(root);
        lvlOrder(root->right, lvl, depth+1);

    }
    
    Node* connect(Node* root) {
        vector<vector<Node*>> lvl;
        lvlOrder(root, lvl, 0);
        for(auto i:lvl){
            for(int j=0;j<i.size()-1;j++){
                i[j]->next = i[j+1];
            }
        }
        return root;
    }
};