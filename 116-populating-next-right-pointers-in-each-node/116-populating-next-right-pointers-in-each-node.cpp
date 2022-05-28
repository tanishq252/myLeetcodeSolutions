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
//     void leveltraverse(Node *root, vector<vector<Node*>> &level,int depth){
//         if(root==NULL) return;
//         if(depth == level.size()){
//             level.push_back({});
//         }
//         level[depth].push_back(root);
//         leveltraverse(root->left, level, depth+1);        
//         leveltraverse(root->right, level, depth+1);
//     }
    
//     Node* connect(Node* root) {
//         vector<vector<Node*>> level;
//         leveltraverse(root, level, 0);
//         for(auto i:level){
//             for(int j=0;j<i.size()-1;j++){
//                 i[j]->next = i[j+1];
//             }
//         }
//         return root;
//     }
    
    void join(Node* root){
        if(!root){
            return;
        }
        
        if(!root->left and !root->right){
            return;
        }
        
        root->left->next = root->right;
        
        if(root->next){
            root->right->next = root->next->left;
        }
        
        join(root->left);
        join(root->right);
    }
    
    Node* connect(Node* root) {
        join(root);
        return root;
    }
};